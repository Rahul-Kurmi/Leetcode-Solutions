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
                // If we want to write continue here then we have to add code 
                // the code that is written after if else 
                temp = "/";
                if(i == path.size()) break;
                i++;
                continue ;
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