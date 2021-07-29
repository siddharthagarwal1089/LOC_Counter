#include <iostream>
#include <string>
using namespace std;

//PROXY BEGIN InstructMsg
class InstructMsg{
public:
//PROXY FN BEGIN
    void startMsg(){
        cout<<"\n---------------Welcome to the LOC Counter program---------------\n\n";
        cout<<"Please note the points while entering the program/file name:\n";
        cout<<"1. Do NOT provide the program/file name by command line argument. It is asked to enter below.\n";
        cout<<"2. Enter the complete program/file name with enxtension and it should be less than 50 characters.\n";
        cout<<"3. If wrong program/file name is entered, this code will terminate with a message to run the code again.\n\n\n";

        cout<<"Please note the points regarding the program/file content and the output:\n\n";
        cout<<"1. The input file MUST have 4 tags:\n";
        cout<<"\ta. //PROXY BEGIN class_name    -> Before the starting of every class. (CLASS NAME is required)\n";
        cout<<"\tb. //PROXY END class_name      -> After the ending of every class. (CLASS NAME is required)\n";
        cout<<"\tc. //PROXY FN BEGIN            -> Before the starting of every method/fucntion in class. (METHOD NAME is not required)\n";
        cout<<"\td. //PROXY FN END              -> After the ending of every method/fucntion in class. (METHOD NAME is not required)\n\n";

        cout<<"2. These 4 specified tags should NOT be INDENTED, i.e any of them should NOT begin with tabs or spaces.\n";
        cout<<"3. Program counts the commented lines also but does not count blank lines.\n";
        cout<<"4. Proxy Name should NOT exceed 100 characters.\n";
        cout<<"5. Proxy LOC considers //PROXY BEG....... and //PROXY EN....... also in the count.\n";
        cout<<"6. Only Total LOC will be shown if the program/file does not contain the specified tags.\n\n";

        cout<<"7. Consider this code file tags to get more familiar with the input file type.\n\n";
    }
//PROXY FN END
};
//PROXY END InstructMsg

//PROXY BEGIN CodeAnalysis
class CodeAnalysis{
public:
    char sentence_read[1000];

//PROXY FN BEGIN
    int compareCharArr(char c_arr1[], char c_arr2[], int n){
        for (int i = 0; i < n; i++){
            if(c_arr1[i] != c_arr2[i]){
                return 0;
            }
        }
        return 1;
    }
//PROXY FN END

//PROXY FN BEGIN
    void proxyNameTransfer(char name_arr[], char full_arr[], int k){
        for (int i = 0; i < 100; i++){
            name_arr[i] = full_arr[i+k];
        }
    }
//PROXY FN END

//PROXY FN BEGIN
    int isSpaceArr(char arr[]){
        int i = 0;
        while (arr[i] != '\0'){
            if (arr[i] != ' '){
                return 0;
            }
            i++;
        }
        return 1;
    }
//PROXY FN END

//PROXY FN BEGIN
    int isBlankLineArr(char arr[]){
        int i = 0;
        while (arr[i] != '\n'){
            if (arr[i] != ' '){
                return 0;
            }
            i++;
        }
        return 1;
    }
//PROXY FN END

//PROXY FN BEGIN
    void fileHandle(char pb[], char pe[], char fb[], char fe[], int prb, int pre, int fnb, int fne){
        char prog_name[50];
        cout<<"Enter the name of the program/file: ";
        cin>>prog_name;
        cout<<"\n";

        FILE *fp1;
        fp1 = fopen(prog_name, "r");
        if (fp1 == NULL){
            cout<<"Error!! Cannot open the file: " << prog_name << endl;
            cout<<"Please try to run the program again entering the correct file name.\n\n";
            exit(1);
        }

        char proxy_name[100];
        int proxy_loc = 0;
        int func_count = 0;
        int total_loc = 0;

        while(fgets(sentence_read, 1000, fp1) != NULL){ 
            if (isBlankLineArr(sentence_read) == 0){
                    total_loc++;
                }
            if (compareCharArr(sentence_read, pb, prb-1) == 1){
                proxyNameTransfer(proxy_name, sentence_read, prb-1);
                cout<<"Proxy Name: "<<proxy_name;
                proxy_loc = 1;
                func_count = 0;
            }
            if (compareCharArr(sentence_read, fb, fnb-1) == 1){
                    func_count++;
            }
            if (compareCharArr(sentence_read, pe, pre-1) != 1){
                if (isBlankLineArr(sentence_read) == 0){
                    proxy_loc++;
                }
                continue;
            }
            cout<<"Number of Methods: "<<func_count<<"\n";
            cout<<"Proxy LOC: "<<proxy_loc<<"\n\n";
        }
        if(isSpaceArr(sentence_read) == 1){
            total_loc--;
        }
        cout<<"Total LOC: "<<total_loc<<"\n\n\n\n";
        fclose(fp1);
    }
//PROXY FN END
};
//PROXY END CodeAnalysis

//PROXY BEGIN Main
//PROXY FN BEGIN
int main(){
    
    InstructMsg im;
    im.startMsg();

    char pr_begin[] = "//PROXY BEGIN ";
    int prb = sizeof(pr_begin)/sizeof(pr_begin[0]);

    char pr_end[] = "//PROXY END ";
    int pre = sizeof(pr_end)/sizeof(pr_end[0]);

    char fn_begin[] = "//PROXY FN BEGIN";
    int fnb = sizeof(fn_begin)/sizeof(fn_begin[0]);

    char fn_end[] = "//PROXY FN END";
    int fne = sizeof(fn_end)/sizeof(fn_end[0]);

    CodeAnalysis ca;
    ca.fileHandle(pr_begin, pr_end, fn_begin, fn_end, prb, pre, fnb, fne);

    return 0;
}
//PROXY FN END
//PROXY END Main