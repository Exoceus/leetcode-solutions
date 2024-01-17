class RandomizedSet
{
public:
    vector<int> vec;
    map<int, int> hashmap;

    RandomizedSet()
    {
        // All operations are O(1)
        // have a vector which stores the values
        // have a map which points to index of item in the vector

        // for removal use map to lookup index of item, then swap that element with last index, update map accordingly (i.e update values for both swaped values)
        // since deletion in C++ map is not O(1), we just change it to -1 to indicate that the value has been deletec
        // then pop_back on vector and remove item from map
    }

    bool insert(int val)
    {
        if (hashmap.count(val) && hashmap[val] != -1)
        {
            return false;
        }

        int new_i = vec.size();
        vec.push_back(val);
        hashmap[val] = new_i;
        return true;
    }

    bool remove(int val)
    {
        if (!hashmap.count(val) || hashmap[val] == -1)
        {
            return false;
        }

        int i = hashmap[val];
        int end = vec[vec.size() - 1];
        hashmap[end] = i;
        vec[i] = end;
        vec.pop_back();
        hashmap[val] = -1;

        return true;
    }

    int getRandom()
    {
        int rand_i = rand() % vec.size();
        return vec[rand_i];
    }
};