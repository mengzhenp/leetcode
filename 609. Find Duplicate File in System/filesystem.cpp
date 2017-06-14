class Solution {
public:
    void parse(map<string, vector<string>>& mapper, string str) {
        int n = str.length();
        string path = "";
        string filename = "";
        string content = "";
        int i = 0;
        while (str.at(i) != ' ') {
            path += str.at(i);
            i++;
        }
        while (i < n) {
            filename = "";
            content = "";
            i += 1; 
            while (str.at(i) != '(') {
                filename += str.at(i);
                i++;
            }
            i += 1;
            while (str.at(i) != ')') {
                content += str.at(i);
                i++;
            }
            i += 1;
            if (mapper.find(content) != mapper.end()) {
                mapper[content].push_back(path + "/" + filename);
            } else {
                vector<string> vals;
                vals.push_back(path + "/" + filename);
                mapper.insert(pair<string, vector<string>>(content, vals));
            }
        }
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> mapper;
        for (int i = 0; i < paths.size(); i++) {
            parse(mapper, paths[i]);    
        }
        map<string, vector<string>>::iterator it;
        it = mapper.begin();
        vector<vector<string>> ans;
        while (it != mapper.end()) {
            if (it->second.size() > 1) ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};