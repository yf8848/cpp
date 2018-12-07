// timeout_queue.h
#pragma once

#include <optional>
#include <unordered_map>
#include <unordered_set>

template <typename Key, typename Value, typename Time>
class timeout_queue
{
public:
    typedef Key key_type;
    typedef Time time_type;
    typedef Value value_type;

    typedef std::unordered_set<key_type> key_set;
    typedef std::unordered_map<time_type, key_set> time_index_type;

    typedef std::pair<time_type, value_type> time_value_pair;
    typedef std::unordered_map<key_type, time_value_pair> key_index_type;
private:
    time_index_type time_index;
    key_index_type key_index;
    time_type time_min_limit;
public:
    timeout_queue(time_type time_min_limit) : time_min_limit(time_min_limit)
    {
    }

    bool
    insert(key_type key, value_type value, time_type time)
    {
        if (key_index.find(key) != key_index.end())
            return false;  // exist key

        if (time < time_min_limit) // will recycle on next check_timeout()
            time = time_min_limit;

        time_index[time].insert(key);
        key_index.emplace(std::move(key), std::make_pair(std::move(time),
                                                         std::move(value)));

        return true;
    }

    std::optional<value_type>
    erase(key_type key)
    {
        auto p = key_index.find(key);
        if (p == key_index.end())
            return std::nullopt;

        time_type time = p->second.first;
        auto value = std::move(p->second.second);

        time_index[time].erase(key);
        key_index.erase(p);

        return value;
    }

    auto
    check_timeout(time_type time_min_limit_new)
    {
        std::unordered_map<key_type, value_type> recycled;

        if (time_min_limit_new < time_min_limit)
            time_min_limit_new = time_min_limit;

        // recycle [time_min_limit, time_min_limit_new]
        for (auto t = time_min_limit, e = time_min_limit_new + 1; t != e; ++t) {
            if (auto p = time_index.find(t); p != time_index.end()) {
                for (auto &key : p->second) {
                    auto p2 = key_index.find(key);
                    auto &value = p2->second.second;
                    recycled.emplace(std::move(key), std::move(value));
                    key_index.erase(p2);
                }
                time_index.erase(p);
            }
        }

        time_min_limit = time_min_limit_new;

        return recycled;
    }
};
// timeout_queue.h

// main.cc
#include <iostream>

using namespace std;

int
main(int argc, char *argv[])
{
    size_t TN = 100; // 时间单位是1/100s
    uint64_t now = time(NULL) * TN;

    timeout_queue<int, string, uint64_t> tq(now);

    auto insert = [&](auto k, auto v, auto t) {
        cout << "insert " << k << " => " << v << " (" << t - now << "): "
             << (tq.insert(k, v, t)? "OK" : "failed") << endl;
    };

    auto erase = [&](auto k) {
        if (auto p = tq.erase(k); p)
            cout << "erase OK: " << k << " => " << *p << endl;
        else
            cout << "erase failed: " << k << endl;
    };

    auto timeout = [&](auto t) {
        cout << "timeout items (" << t - now << "):" << endl;
        auto v = tq.check_timeout(t);
        for (auto i = v.begin(), e = v.end(); i != e; ++i)
            cout << "    " << i->first << " => " << i->second << endl;
    };

    insert(1, "A", now + 2 * TN);
    insert(2, "B", now + 5 * TN);
    insert(1, "C", now + 5 * TN);
    insert(3, "D", now + 8 * TN);

    timeout(now + 3 * TN);

    erase(1);
    erase(2);

    timeout(now + 8 * TN);
}
