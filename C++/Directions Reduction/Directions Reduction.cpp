using namespace std;
class DirReduction
{
    public:
        
    static vector<string> dirReduc(vector<string> &arr){
        vector<string> solution;
        vector<string> checkIfChanging;
        solution = arr;
        checkIfChanging = {};
        while(checkIfChanging != solution){
            checkIfChanging = solution;

            for(int i =1;i<solution.size();i++){
                if((solution[i-1].front() == 'N' && solution[i].front() == 'S') || (solution[i].front() == 'N' && solution[i-1].front() == 'S')){
                    solution.erase(solution.begin() + i);
                    solution.erase(solution.begin() + (i - 1));
                }
                if((solution[i-1].front() == 'W' && solution[i].front() == 'E') || (solution[i].front() == 'W' && solution[i-1].front() == 'E')){
                    solution.erase(solution.begin() + i);
                    solution.erase(solution.begin() + (i - 1));
                }
            }
        }
        return solution;
    };
};
