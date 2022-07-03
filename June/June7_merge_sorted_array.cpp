class Solution {
public:
    void merge(vector<int>& arr1, int size1, vector<int>& arr2, int size2) {
        vector<int> ans;
        int i = 0, k = 0, j = 0;
    while (i < size1 && j < size2) {
        if(arr1[i] < arr2[j]) {
            //ans[k++] = arr1[i];
            ans.push_back(arr1[i]);
            i++;
        } else {
            ans.push_back(arr2[j]);
            //ans[k++] = arr2[j];
            j++;
        } 
        
     
   } while(i < size1) {
       // ans[k++] = arr1[i];
        ans.push_back(arr1[i]);
        i++;
    } while (j < size2) {
        //ans[k++] = arr2[j];
         ans.push_back(arr2[j]);
        j++;
    }
        for(int i = 0;i < ans.size();i++){
            arr1[i] = ans[i];
        }
    }
};
