class TimeMap {
public:

    unordered_map <string, map <int, string >> m;
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        m[key].insert({timestamp, value});
    }

    //called get(key, timestamp)
    //get value for the key where its saved timestamp is less than or equal to the requested timestamp
    
    string get(string key, int timestamp) 
    {
        //first element strictly greater than timestamp

        auto it = m[key].upper_bound(timestamp);

        if(it == m[key].begin())
        {
            return "";
        }
        else
        {
            auto correct_it = prev(it);

            return correct_it -> second;
        }

    }
};
