void LPS(string txt,vector<int> &lps){
    lps[0] = 0;                   
    int len = 0;
    int i=1;
    while (i<txt.length()){
        if(txt[i]==txt[len]){   
            len++;
            lps[i] = len;
            i++;
        }
        else{                   
            if(len==0){         
                lps[i] = 0;
                i++;
            }
            else{              
                len = lps[len-1];
            }
        }
    }
}

int main(){
  string pattern;
  cin>>pattern;
  vector<int> lps(pattern.length());
  LPS(pattern,lps);
  return 0;
}


