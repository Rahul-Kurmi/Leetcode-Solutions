class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";
        temp.push_back('/');
        int i = 1;

        while(true){

            for(; i < path.size(); i++){
                if(path[i] == '/') break;
                temp += path[i];
            }

            if(temp == "/" || temp == "/."){
                // We are just ignoring this not doing anything here,
                // BUt we can't write continue here if written --> BLUNDER
                // As we have to run code that is written after if else as 
            }
            else if(temp == "/.."){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(temp);
            }

            temp = "/";

            if(i == path.size()) break;

            i++;
        }

        path = "";

        while(!st.empty()){
            path = st.top() + path;
            st.pop();
        }

        if(path == "") return "/";

        return path;
    }
};