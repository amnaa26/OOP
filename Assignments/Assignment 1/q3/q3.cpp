#include <iostream>
#include <vector>

using namespace std;

class ChessPiece {
private:
    string name;
    char symbol;
    string color;

public:
    ChessPiece() : name("Pawn"), symbol('p'), color("White") {}

    // Parameterized Constructor
    ChessPiece(string name, char symbol, string color) : name(name), symbol(symbol), color(color) {}

	//Getters
    string getName() const {
        return name;
    }
    char getSymbol() const {
        return symbol;
    }
    string getColor() const {
        return color;
    }

    // Setter
    void setColor(string color) {
        this->color = color;
    }
};

class ChessBoard {
private:
    vector<vector<ChessPiece*>> board;

public:
    ChessBoard() {
        board.resize(8, vector<ChessPiece*>(8, nullptr));
        initializeBoard();
    }

    // Destructor
    ~ChessBoard() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                delete board[i][j];
            }
        }
    }

    void initializeBoard() {
        // White pieces
        board[0][0] = new ChessPiece("Rook", 'r', "White");
        board[0][1] = new ChessPiece("Knight", 'n', "White");
        board[0][2] = new ChessPiece("Bishop", 'b', "White");
        board[0][3] = new ChessPiece("Queen", 'q', "White");
        board[0][4] = new ChessPiece("King", 'k', "White");
        board[0][5] = new ChessPiece("Bishop", 'b', "White");
        board[0][6] = new ChessPiece("Knight", 'n', "White");
        board[0][7] = new ChessPiece("Rook", 'r', "White");
        for (int j = 0; j < 8; ++j) {
            board[1][j] = new ChessPiece("Pawn", 'p', "White");
        }

        // Black pieces
        board[7][0] = new ChessPiece("Rook", 'R', "Black");
        board[7][1] = new ChessPiece("Knight", 'N', "Black");
        board[7][2] = new ChessPiece("Bishop", 'B', "Black");
        board[7][3] = new ChessPiece("Queen", 'Q', "Black");
        board[7][4] = new ChessPiece("King", 'K', "Black");
        board[7][5] = new ChessPiece("Bishop", 'B', "Black");
        board[7][6] = new ChessPiece("Knight", 'N', "Black");
        board[7][7] = new ChessPiece("Rook", 'R', "Black");
        for (int j = 0; j < 8; ++j) {
            board[6][j] = new ChessPiece("Pawn", 'P', "Black");
        }
    }

    // Display the current state of the board
    void display() const {
        cout << "  a b c d e f g h\n";
        for (int i = 0; i < 8; ++i) {
            cout << 8 - i << " ";
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] != nullptr) {
                    cout << board[i][j]->getSymbol() << " ";
                } else {
                    cout << ". ";
                }
            }
            cout << 8 - i << endl;
        }
        cout << "  a b c d e f g h\n";
    }

    // Moving pieces
    bool movePiece(string source, string destination) {
        int sourceRow = 8 - (source[1] - '0');
        int sourceCol = source[0] - 'a';
        int destRow = 8 - (destination[1] - '0');
        int destCol = destination[0] - 'a';

        if (isValidMove(sourceRow, sourceCol, destRow, destCol)) {
            delete board[destRow][destCol];
            board[destRow][destCol] = board[sourceRow][sourceCol];
            board[sourceRow][sourceCol] = nullptr;
            return true;
        } else {
            return false;
        }
    }

private:
    // Check if the move is valid
    bool isValidMove(int sourceRow, int sourceCol, int destRow, int destCol) const {
        if (board[sourceRow][sourceCol] == nullptr || board[destRow][destCol] != nullptr) {
            return false; // Source is empty or destination is occupied
        }

        char pieceSymbol = board[sourceRow][sourceCol]->getSymbol();

        // Check if the move is valid for a knight or pawn on the first turn
        if (pieceSymbol == 'n' || pieceSymbol == 'N' || pieceSymbol == 'p' || pieceSymbol == 'P') {
            int rowDiff = abs(destRow - sourceRow);
            int colDiff = abs(destCol - sourceCol);
            if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2) || (rowDiff == 1 && colDiff == 0)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
	cout << "Creator: Amna(23k-0066)" << endl << "Program: Chess" << endl << "--------Starting the Program--------" << endl;
    ChessBoard board;
    board.display();
    
    cout << endl;
    cout << "Moving knight from b8 to a6: ";
    board.movePiece("b8", "a6") ? cout << "Success\n" : cout << "Failed\n";
    board.display();

    cout << endl;
    cout << "Moving knight from b8 to d7: ";
    board.movePiece("b8", "d7") ? cout << "Success\n" : cout << "Failed\n";
    board.display();

    return 0;
}

