/****************************************************************************
**                                MIT License
**
** Copyright (C) 2020 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Marc Mutz <marc.mutz@kdab.com>
**
** This file is part of KDToolBox (https://github.com/KDAB/KDToolBox).
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, ** and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice (including the next paragraph)
** shall be included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF ** CONTRACT, TORT OR OTHERWISE,
** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
****************************************************************************/

#include <QTest>

#include <k20/deque.h>
#include <k20/forward_list.h>
#include <k20/list.h>
#include <k20/map.h>
#include <k20/set.h>
#include <k20/string.h>
#include <k20/unordered_map.h>
#include <k20/unordered_set.h>
#include <k20/vector.h>


class tst_erase_if : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void erase_empty_vector_int() { erase_impl<std::vector<int>>(); }
    void erase_empty_vector_string() { erase_impl<std::vector<std::string>>(); }
    void erase_if_empty_vector_int() { erase_if_impl<std::vector<int>>(); }
    void erase_if_empty_vector_string() { erase_if_impl<std::vector<std::string>>(); }

    void erase_vector_int() { erase_impl<std::vector<int>>({1, 0, 2, 1, -3}, 1, 2); }
    void erase_if_vector_int() { erase_if_impl<std::vector<int>>({1, 0, 2, 1, -3}, 2, 1); }

    void erase_empty_deque_int() { erase_impl<std::deque<int>>(); }
    void erase_empty_deque_string() { erase_impl<std::deque<std::string>>(); }
    void erase_if_empty_deque_int() { erase_if_impl<std::deque<int>>(); }
    void erase_if_empty_deque_string() { erase_if_impl<std::deque<std::string>>(); }

    void erase_deque_int() { erase_impl<std::deque<int>>({1, 0, 2, 1, -3}, 1, 2); }
    void erase_if_deque_int() { erase_if_impl<std::deque<int>>({1, 0, 2, 1, -3}, 2, 1); }

    void erase_empty_list_int() { erase_impl<std::list<int>>(); }
    void erase_empty_list_string() { erase_impl<std::list<std::string>>(); }
    void erase_if_empty_list_int() { erase_if_impl<std::list<int>>(); }
    void erase_if_empty_list_string() { erase_if_impl<std::list<std::string>>(); }

    void erase_list_int() { erase_impl<std::list<int>>({1, 0, 2, 1, -3}, 1, 2); }
    void erase_if_list_int() { erase_if_impl<std::list<int>>({1, 0, 2, 1, -3}, 2, 1); }

    void erase_empty_forward_list_int() { erase_impl<std::forward_list<int>>(); }
    void erase_empty_forward_list_string() { erase_impl<std::forward_list<std::string>>(); }
    void erase_if_empty_forward_list_int() { erase_if_impl<std::forward_list<int>>(); }
    void erase_if_empty_forward_list_string() { erase_if_impl<std::forward_list<std::string>>(); }

    void erase_forward_list_int() { erase_impl<std::forward_list<int>>({1, 0, 2, 1, -3}, 1, 2); }
    void erase_if_forward_list_int() { erase_if_impl<std::forward_list<int>>({1, 0, 2, 1, -3}, 2, 1); }

    void erase_empty_string() { erase_impl<std::string>(); }
    void erase_if_empty_string() { erase_if_impl<std::string>(); }

    void erase_string() { erase_impl<std::string>({'H', 'e', 'l', 'l', 'o'}, 'l', 2); }
    void erase_if_string() { erase_if_impl<std::string>({'W', 'o', 'r', 'l', 'd'}, 'r', 1); }

    void erase_if_empty_map_int_string() { erase_if_impl<std::map<int, std::string>>(); }
    void erase_if_empty_multimap_int_string() { erase_if_impl<std::multimap<int, std::string>>(); }
    void erase_if_empty_set_int() { erase_if_impl<std::set<int>>(); }
    void erase_if_empty_multiset_string() { erase_if_impl<std::multiset<std::string>>(); }
    void erase_if_empty_umap_int_string() { erase_if_impl<std::unordered_map<int, std::string>>(); }
    void erase_if_empty_umultimap_int_string() { erase_if_impl<std::unordered_multimap<int, std::string>>(); }
    void erase_if_empty_uset_int() { erase_if_impl<std::unordered_set<int>>(); }
    void erase_if_empty_umultiset_string() { erase_if_impl<std::unordered_multiset<std::string>>(); }

    void erase_if_map_int_string() { erase_if_impl<std::map<int, std::string>>({{1, "one"}, {2, "two"}}, {2, "two"}, 1); }
    void erase_if_multimap_int_string() { erase_if_impl<std::multimap<int, std::string>>({{1, "one"}, {2, "two"}, {2, "zwei"}}, {2, "two"}, 1); }
    void erase_if_set_int() { erase_if_impl<std::set<int>>({-10, 2, 4, 5}, 2, 1); }
    void erase_if_multiset_string() { erase_if_impl<std::multiset<std::string>>({"1", "2", "2", "1", "3"}, "2", 2); }
    void erase_if_umap_int_string() { erase_if_impl<std::unordered_map<int, std::string>>({{1, "one"}, {2, "two"}}, {2, "two"}, 1); }
    void erase_if_umultimap_int_string() { erase_if_impl<std::unordered_multimap<int, std::string>>({{1, "one"}, {2, "two"}, {2, "zwei"}}, {2, "two"}, 1); }
    void erase_if_uset_int() { erase_if_impl<std::unordered_set<int>>({-10, 2, 4, 5}, 2, 1); }
    void erase_if_umultiset_string() { erase_if_impl<std::unordered_multiset<std::string>>({"1", "2", "2", "1", "3"}, "2", 2); }

private:
    template <typename Container>
    using value_type = typename Container::value_type;
    template <typename Container>
    using size_type = typename Container::size_type;

    template <typename Container>
    void erase_impl(std::initializer_list<value_type<Container>> il = {},
                    const value_type<Container>& v = {},
                    size_type<Container> expected = 0)
    {
        const Container c = il;
        {
            Container copy = c;
            QCOMPARE(k20::erase(copy, v), expected);
            if (expected > 0)
                QVERIFY(copy != c);
            else
                QVERIFY(copy == c);
        }
    }
    template <typename Container>
    void erase_if_impl(std::initializer_list<value_type<Container>> il = {},
                       const value_type<Container>& v = {},
                       size_type<Container> expected = 0)
    {
        const Container c = il;
        {
            Container copy = c;
            QCOMPARE(k20::erase_if(copy, [&](const auto &e) { return e == v; }), expected);
            if (expected > 0)
                QVERIFY(copy != c);
            else
                QVERIFY(copy == c);
        }
    }
};

QTEST_APPLESS_MAIN(tst_erase_if)
#include "tst_erase_if.moc"
