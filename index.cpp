#include<bits/stdc++.h>
using namespace std;

struct Row{
    vector<string>values;
};

struct Table{
    string name;
    vector<string>columns;
    vector<Row>rows;  
};

class Database{
    private:
    unordered_map<string, Table> tableMap;
    public:
    
    void createTable(string name, vector<string>columns){
        if(tableMap.find(name)!= tableMap.end()){
            cout << "Error: Table " << name << " already exists.\n";
            return;
        }
        Table t;
        t.name=name;
        t.columns=columns;
        t.rows={};
        tableMap[name]=t;
        cout << "Table " << name << " created successfully.\n";
    }

    void insertRow(const string& table , const vector<string>&values)
    {
      if(tableMap.find(table)==tableMap.end())
      {
        cout<<"Error:"<<table<<" Not Found.\n";
        return;
      }
      tableMap[table].rows.push_back({values});
      cout << "Row inserted into " << table << "\n";
    }

    void selectAll(const string& table , const vector<string>&cc={})
    {
        if(tableMap.find(table)==tableMap.end()){
            cout << "Table not found\n";
            return;
        }

        auto &t= tableMap[table];
        // for(auto &col :t.columns) cout << col << "\t";
        // cout << "\n---------------------\n";
        for(auto &row :t.rows)
        {
           if(cc.size()==0)
        {
            for (auto &v : row.values) cout << v << " ";
            cout << "\n";
        }
        else
        {
            for(auto &c: cc)
            {
                int idx=-1;
                for(int j=0;j<t.columns.size();j++)
                {
                    if(t.columns[j]==c) idx=j;
                }
                if(idx!=-1) cout<<row.values[idx]<<" ";
                else cout<<"NULL ";
            }
            cout<<"\n";
        }
        }
    }


    void execute(string query) {
      if (query.find("CREATE") == 0) {
        // Example query: CREATE Students ID Name Age City
        string temp, tableName;
        stringstream ss(query);
        
        ss >> temp >> tableName;  // temp="CREATE", tableName="Students"

        vector<string> columns;
        string col;

        // Keep reading until no words left
        while (ss >> col) {
            columns.push_back(col);
        }

        createTable(tableName, columns);
    }
    else if (query.find("INSERT") == 0) {
        // Example query: INSERT Students 1 meet 19 pune
        string temp, tableName;
        stringstream ss(query);
        
        ss >> temp >> tableName;  // temp="INSERT", tableName="Students"

        vector<string> values;
        string val;

        // Keep reading until no words left
        while (ss >> val) {
            values.push_back(val);
        }

        insertRow(tableName, values);
    }
    else if (query.find("SELECT") == 0) {
        // Example query: SELECT Students
        string temp, tableName;
        stringstream ss(query);
        
        ss >> temp;
        vector<string>cc;
        string col;
        // cout<<query<<endl;
        while(ss>>col)
        {
            if(tableMap.find(col)!=tableMap.end())
            {
                tableName=col;
                break;
            }
            else
            {
                cc.push_back(col);
            }
        }
        // cout<<cc.size()<<endl;
         vector<tuple<string, string, string>> conditions; // {column, operator, value}
        vector<string> logic; // AND / OR / NOT

    string word;
    while (ss >> word) {
        if (word == "AND" || word == "OR" || word == "NOT") {
            // If word is a logical operator, save it
            logic.push_back(word);
        } else {
            // Otherwise, it’s a column name followed by operator and value
            string op, val;
            ss >> op >> val; // e.g., Age = 19
            conditions.push_back({word, op, val});
        }
    } 
     auto &t = tableMap[tableName]; 
    if(cc.size()==0)
{
    for (auto &c : t.columns) cout << c << " ";
    cout << "\n----------------\n";
}
else
{
    for (auto &c : cc) cout << c << " ";
    cout << "\n----------------\n";
}
    if(conditions.size()==0){
        selectAll(tableName,cc);
        return;
    }
    if (conditions.empty() && query.find("WHERE") != string::npos) {
    cout << "Warning: WHERE clause is empty, selecting all rows.\n";
    return;
}

   // get the table

// Print table header


for (auto &row : t.rows) {
    bool result = true; // start with first condition
    for (int i = 0; i < conditions.size(); i++) {
    string col = get<0>(conditions[i]);
    string op  = get<1>(conditions[i]);
    string val = get<2>(conditions[i]); // Find the column indexgit reset --hard origin/main
        int idx = -1;
        for (int j = 0; j < t.columns.size(); j++)
            if (t.columns[j] == col) idx = j;

        if (idx == -1) continue; // skip if column not found

        // Evaluate the condition (only '=' for now)
        bool cond = (op == "=") ? (row.values[idx] == val) : false;

        // Combine with previous result using logic array
        if (i == 0) {
            result = cond; // first condition
        } else {
            string oper = logic[i - 1]; // AND / OR / NOT
            if (oper == "AND") result = result && cond;
            else if (oper == "OR") result = result || cond;
            else if (oper == "NOT") result = !cond; // negate current condition
        }
    }

    if (result) {
        if(cc.size()==0)
        {
            for (auto &v : row.values) cout << v << " ";
            cout << "\n";
        }
        else
        {
            for(auto &c: cc)
            {
                int idx=-1;
                for(int j=0;j<t.columns.size();j++)
                {
                    if(t.columns[j]==c) idx=j;
                }
                if(idx!=-1) cout<<row.values[idx]<<" ";
                else cout<<"NULL ";
            }
            cout<<"\n";
        }
    }
}

 }
    }
};


int main(){
    Database db;
    string query;

    while(true)
    {
        cout<<"SQL> ";
        getline(cin,query);
        if(query=="exit") break;
        db.execute(query);
    }
    return 0;
}

  

