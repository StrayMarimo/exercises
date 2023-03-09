
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <utility>

using namespace std;

map<int, vector<int> > blocks;

void displayBlocks() {
    for (auto m: blocks) {
        string line = to_string(m.first) + ": ";
        for (auto &x : m.second)
            line = line + to_string(x) + " ";
        
        line.pop_back();
        cout << line << endl;
    }
    
}

int getCommand(string cmds[]) {
    if (cmds[0] == "move") {
        if (cmds[2] == "onto")
            return 1;
        if (cmds[2] == "over")
            return 2;
    } else if (cmds[0] == "pile"){
        if (cmds[2] == "onto")
            return 3;
        else if (cmds[2] == "over")
            return 4;
    } else if (cmds[0] == "quit")
        return 5;
    return - 1;
}

pair<int, int> searchElement(int target){
    for (int i = 0; i < blocks.size(); i++) {
        int key = (i + target) % blocks.size();
        for (int j = 0; j < blocks[key].size(); j++) {
            if (blocks[key][j] == target)
                return make_pair(key, j);
        }
    }
    
    return make_pair(-1, -1);
        
}

void resetElements(int target, pair<int, int> coords) {
  
    int pos = blocks[coords.first].size() - 1;
   
    while (blocks[coords.first][pos] != target) {
     
        blocks[blocks[coords.first][pos]].push_back(blocks[coords.first][pos]);
        blocks[coords.first].pop_back();
        pos = blocks[coords.first].size() - 1;
    }
}

void pushMultiple(pair<int, int> coords, int b) {
 
    int i = coords.second;
    
    while (i < blocks[coords.first].size()) {
        blocks[b].push_back(blocks[coords.first][i]);
        blocks[coords.first].erase(blocks[coords.first].begin() + i);
    }
}



int main() {
    int n, case_cmd;
    string command, token;
   
    pair <int, int> coords_a, coords_b;
    
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++)
        blocks[i].push_back(i);
    
    while(getline(cin, command)) {
        istringstream ss(command);
        string parsed_command[4];
        int i = 0;
        while (getline(ss, token, ' ')) {
            parsed_command[i] = token;
            i++;
        }
        case_cmd = getCommand(parsed_command);
        
        if (case_cmd == 5) {
            displayBlocks();
            return 0;
        }
        

        
        int a = stoi(parsed_command[1]);
        int b = stoi(parsed_command[3]);
        
        coords_a = searchElement(a);
        coords_b = searchElement(b);
        
        if(coords_a.first == coords_b.first) continue;
        
        switch (case_cmd) {
            case 1:
                if (blocks[coords_a.first].size() != coords_a.second + 1)
                    resetElements(a, coords_a);
                if (blocks[coords_b.first].size() != coords_b.second + 1)
                    resetElements(b, coords_b);
                blocks[coords_a.first].pop_back();
                blocks[coords_b.first].push_back(a);
                break;
            case 2:
                if (blocks[coords_a.first].size() != coords_a.second + 1)
                    resetElements(a, coords_a);
                blocks[coords_b.first].push_back(a);
                blocks[coords_a.first].pop_back();
                break;
            case 3:
                if (blocks[coords_b.first].size() != coords_b.second + 1)
                    resetElements(b, coords_b);
                pushMultiple(coords_a, coords_b.first);
                break;
            case 4:
                pushMultiple(coords_a, coords_b.first);
                break;
            default: break;
        }
    }
     displayBlocks();
    
    return 0;
}
