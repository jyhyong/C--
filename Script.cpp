#include <iostream>
#include <string>
#include <vector>


using namespace std;

string WheelOfLuck(){
    string result;

    int goldProb = 1;
    int silverProb = 2;
    int bronzeProb = 3;
    int steelProb = 94;

    int randomInt = 1 + (rand() % 100);

    if (randomInt <= steelProb)
        return "STEEL";
    if (randomInt <= (bronzeProb + steelProb))
        return "BRONZE";
    if (randomInt <= (silverProb + bronzeProb + steelProb))
        return "SILVER";
    if (randomInt <= (goldProb + silverProb + bronzeProb + steelProb))
        return "GOLD";
    
    return "STEEL";
}

string Engine(int currSequence){
    string result;
    int bronzeSection = 10;
    int silverSection = 30;
    int goldSection = 90;

    if (currSequence % bronzeSection == 0){
        // reach bronze section
        result = "BRONZE";
        if (currSequence % silverSection == 0){
            // reach silver section
            result = "SILVER";
            if (currSequence % goldSection == 0){
                // reach gold section
                result = "GOLD";
            }
        }
    }
    else{
        result = WheelOfLuck();
    }
    
    return result;
}

vector<vector<string>> GenerateSample(){
    int currSequence;
    vector<vector<string>> result; 

    for (int j = 0; j < 100; j++){
        vector<string> loop90Times;
        for (int i = 0; i < 90; i++){
            loop90Times.push_back(Engine(i+1));
        }
        result.push_back(loop90Times);
    }

    return result;
}

vector<vector<int>> ProcessData(vector<vector<string>> data){    
    vector<vector<string>>::iterator row;
    vector<string>::iterator col;

    vector<vector<int>> result;

    for (row = data.begin(); row != data.end(); row++) {
        vector<int> instance;
        int steelCount = 0, bronzeCount = 0, silverCount = 0, goldCount = 0;

        for (col = row->begin(); col != row->end(); col++) {
            if (*col == "STEEL"){
                steelCount += 1;
            }
            if (*col == "BRONZE"){
                bronzeCount += 1;
            }
            if (*col == "SILVER"){
                silverCount += 1;
            }
            if (*col == "GOLD"){
                goldCount += 1;
            }
        }
        instance.push_back(steelCount);
        instance.push_back(bronzeCount);
        instance.push_back(goldCount);
        instance.push_back(goldCount);

        result.push_back(instance);
    }

    return result;
}

void main(){
    cout << "START" << endl;

    try{
        vector<vector<int>> result = ProcessData(GenerateSample());

        vector<vector<int>>::iterator row;
        vector<int>::iterator col;

        for (row = result.begin(); row != result.end(); row++) {
            for (col = row->begin(); col != row->end(); col++) {
                cout << *col << " "; 
            }
            cout << endl;
        }                   
    }
    catch (...){
        cout << "Error" << endl;
    }
}
