class Spreadsheet {
public:
    vector<vector<int>>sheet;
    Spreadsheet(int rows) {
        sheet.assign(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;
        sheet[row][col]=value;
    }
    
    void resetCell(string cell) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;
        sheet[row][col]=0;
    }
    int solver(string k){
        if(isdigit(k[0])){
            return stoi(k);
        }
        int col=k[0]-'A';
        int row=stoi(k.substr(1))-1;
        return sheet[row][col];
    }
    int getValue(string formula) {
        string s=formula.substr(1);
        int idx=s.find('+');
        string left=s.substr(0,idx);
        string right=s.substr(idx+1);
        int v1=solver(left);
        int v2=solver(right);
        return v1+v2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */