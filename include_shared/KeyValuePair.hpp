#pragma once

template <typename Key, typename Elem>
class KeyValuePair
{
private:
    Key k;
    Elem e;

public:
    KeyValuePair() {}
    KeyValuePair(Key _k, Elem _e)
    {
        k = _k;
        e = _e;
    }
    KeyValuePair(const KeyValuePair &KVparir)
    {
        k = KVparir.k;
        e = KVparir.e;
    }
    void operator=(const KeyValuePair &KVparir)
    {
        k = KVparir.k;
        e = KVparir.e;
    }

    Key key() { return k; }
    Elem Value() { return e; }
};