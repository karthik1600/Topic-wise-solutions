#include<bits/stdc++.h>
using namespace std;
enum Type{NORMAL,SNAKE,LADDER};
class Dice{
public:
	int roll_dice(){
		return 1 + ( rand() % 6 ); // gives 1 -- 6
	}
};
class Player{
private:
	string name;
	int pos;
public:

	Player(string name){
		this->name = name;
        this->pos = 0;
    }
	void set_pos(int pos){
		this->pos = pos;
    }
	int get_current(){
		return pos;
	}
	string get_name(){
		return name;
	}
};
class Cell{
	int end;
	Type type;
public:
	Cell(int end,int t){
		this->type = (Type)t;
		this->end = end;
	}
	int get_end(){
		return end;
	}
	int get_type(){
		return type;
	}
	void set_end(int end){
		this->end = end;
	}
	void set_type(Type type){
		this->type = type;
	}
};
class Board{
private:
	vector<Cell*> cells;
public:
	Board(int n,vector<pair<int,int>> ladders,vector<pair<int,int>> snakes){
		cells.resize(n+1);
		for(int i=1;i<n+1;i++){
			cells[i] = new Cell(i,0);
		}
		for(auto ladder : ladders){
			cells[ladder.first]->set_type(LADDER);
			cells[ladder.first]->set_end(ladder.second);
		}
		for(auto snake : snakes){
			cells[snake.first]->set_type(SNAKE);
			cells[snake.first]->set_end(snake.second);
		}
	}
	int get_cell_type(int pos){
		return cells[pos]->get_type();
	}
	int get_cell_end(int pos){
		return cells[pos]->get_end();
	}
};
class Game{
	Board* board;
	Dice dice;
	int size_of_board;
	vector<Player> players;
public:
	Game(int size_of_board,vector<pair<int,int>> ladders,vector<pair<int,int>> snakes,vector<Player> players){
        this->players = players;
        board = new Board(size_of_board,ladders,snakes);
        this->size_of_board = size_of_board;
		
	}
	string start(){
        while(true){
            for (int i = 0;i<players.size();i++)
            {
                
                bool valid=false;
                int current_pos = players[i].get_current();
                cout << players[i].get_name() << " : " << current_pos << " : ";
                int new_pos = current_pos;
                do{
                    new_pos = current_pos + dice.roll_dice(); 
                    if(new_pos<=size_of_board)valid=true; // if it is within size
				}while(valid==false); // if new_pos > size eg 101

				while(board->get_cell_type(new_pos)!=NORMAL){
						new_pos = board->get_cell_end(new_pos);
				} //if we go down snake and then meet another snake
                cout << new_pos << endl;
                players[i].set_pos(new_pos);
                if(new_pos==size_of_board)return players[i].get_name();
            }
        }

	}
};
int main(){
	int size_of_board;
	vector<pair<int,int>> ladders;
	vector<pair<int,int>> snakes;
	vector<Player> players;
	int n_pl;
	cout<<"size of board"<<endl;
	cin>>size_of_board;
	cout<<"\nno. of Players"<<endl;
	cin>>n_pl;
	string t;
	for(int i=1;i<=n_pl;i++){
		cout<<"\nenter player "<<i<<"name : ";
		cin>>t;
		players.push_back(Player(t));
	}
	cout<<endl<<"enter no. of ladders: ";
	int l;
	cin>>l;
	for(int i=0;i<l;i++){
		cout<<"\nenter ladder beg and end: ";
		int u,b;
		cin>>u>>b;
		ladders.push_back({u,b}); 
	}
	cout<<endl<<"enter no. of snakes: ";
	int sn;
	cin>>sn;
	for(int i=0;i<sn;i++){
		cout<<"\nenter snakes beg and end: ";
		int u,b;
		cin>>u>>b;
		snakes.push_back({u,b}); 
	}
	cout<<endl;
	Game game(size_of_board,ladders,snakes,players);
	cout<<game.start()<<" won the game";
}