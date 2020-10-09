class Solution {
public:
    string defangIPaddr(string address) {
        string dot = "[.]";
        for(int i=0;i<address.size();i++){
            if(address[i]=='.'){
                address.replace(i,1,dot);
                i+=3;
            }
        }
        return address;
    }
};
