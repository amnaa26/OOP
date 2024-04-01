#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#ifdef _WIN32
#include <conio.h>
#else
#include <unistd.h>
#endif

using namespace std;

class User {
protected:
    string name;
    string email;
    string password;

public:
    User() {}

    User(const string &name, const string &email, const string &password) : name(name), email(email), password(password) {}

    string getName() const {
        return name;
    }

    string getEmail() const {
        return email;
    }

    bool verifyPassword(const string &inputPassword) const {
        return password == inputPassword;
    }

    virtual void viewProfile() const = 0;

    virtual ~User() {}
};

class RegularUser : public User {
private:
    static const int MAX_FEED_SIZE = 10;
    int feedSize = 0;
    int postCount = 0;

public:
    class Post {
    public:
        int postId;
        string content;
        int likes = 0;
        int views = 0;
        vector<string> comments;

        Post(int id, const string &content) : postId(id), content(content) {}

        void addLike() {
            likes++;
        }

        void addComment(const string &comment) {
            comments.push_back(comment);
        }

        void increaseViews() {
            views++;
        }

        void display() const {
            cout << "Post ID: " << postId << endl;
            cout << "Content: " << content << endl;
            cout << "Likes: " << likes << ", Views: " << views << endl;
    
            if (comments.empty()) {
                cout << "Comments: 0" << endl;
            } else {
                cout << "Comments:" << endl;
                for (const auto& comment : comments) {
                    cout << "- " << comment << endl;
                }
            }
        }

        ~Post() {}
    };

    Post* feed[MAX_FEED_SIZE];

public:
    RegularUser() {}

    RegularUser(const string &name, const string &email, const string &password) : User(name, email, password) {}

    void viewProfile() const override {
        cout << "Username: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "User Type: Regular User" << endl;
    }

    void addToFeed(Post* post) {
        if (feedSize < MAX_FEED_SIZE) {
            feed[feedSize++] = post;
        } else {
            cout << "Feed is full!" << endl;
        }
    }

    void addPost(const string &content) {
        if (postCount < MAX_FEED_SIZE) {
            feed[feedSize++] = new Post(postCount, content);
            postCount++;
        } else {
            cout << "Cannot add more posts!" << endl;
        }
    }

    void likePost(Post& post) {
        post.addLike();
    }

    void commentOnPost(Post& post, const string& comment) {
        post.addComment(comment);
    }

    void viewFeed() const {
        cout << "\nFeed for " << name << ":" << endl;
        for (int i = 0; i < feedSize; i++) {
            feed[i]->display();
        }
    }

    int getFeedSize() const {
        return feedSize;
    }

    ~RegularUser() {
        for (int i = 0; i < feedSize; i++) {
            delete feed[i];
        }
    }
};

class BusinessUser : public User {
private:
    int promotedPosts = 0;
    static const int MAX_PROMOTED_POSTS = 10;
    static const int MAX_FEED_SIZE = 10;
    int feedSize = 0;
    int postCount = 0;

public:
    class Post {
    public:
        int postId;
        string content;
        int likes = 0;
        int views = 0;
        vector<string> comments;

        Post(int id, const string &content) : postId(id), content(content) {}

        void addLike() {
            likes++;
        }

        void addComment(const string &comment) {
            comments.push_back(comment);
        }

        void increaseViews() {
            views++;
        }

        void display() const {
            cout << "Post ID: " << postId << endl;
            cout << "Content: " << content << endl;
            cout << "Likes: " << likes << ", Views: " << views << endl;
    
            if (comments.empty()) {
                cout << "Comments: 0" << endl;
            } else {
                cout << "Comments:" << endl;
                for (const auto& comment : comments) {
                    cout << "- " << comment << endl;
                }
            }
        }

        ~Post() {}
    };

    Post* feed[MAX_FEED_SIZE];

public:
    BusinessUser() {}

    BusinessUser(const string &name, const string &email, const string &password) : User(name, email, password) {}

    void viewProfile() const override {
        cout << "Username: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "User Type: Business User" << endl;
    }

    void addToFeed(Post* post) {
        if (feedSize < MAX_FEED_SIZE) {
            feed[feedSize++] = post;
        } else {
            cout << "Feed is full!" << endl;
        }
    }

    void addPost(const string &content) {
        if (postCount < MAX_FEED_SIZE) {
            feed[feedSize++] = new Post(postCount, content);
            postCount++;
        } else {
            cout << "Cannot add more posts!" << endl;
        }
    }

    void likePost(Post& post) {
        post.addLike();
    }

    void commentOnPost(Post& post, const string& comment) {
        post.addComment(comment);
    }

    void promotePost(Post& post) {
        if (promotedPosts < MAX_PROMOTED_POSTS) {
            post.addLike();
            post.addLike();
            post.increaseViews();
            post.increaseViews();
            post.increaseViews();
            promotedPosts++;
        } else {
            cout << "You have reached the maximum limit for promoted posts!" << endl;
        }
    }

    int getFeedSize() const {
        return feedSize;
    }

    void viewFeed() const {
        cout << "\nBusiness User Feed:" << endl;
        for (int i = 0; i < feedSize; i++) {
            feed[i]->display();
            cout << endl;
        }
    }

    ~BusinessUser() {
        for (int i = 0; i < feedSize; i++) {
            delete feed[i];
        }
    }
};



int main() {
    vector<RegularUser> regularUsers;
    vector<BusinessUser> businessUsers;

    cout << "\nCreator: Amna(23K-0066)" << endl;
    cout << "\nWelcome to our Social Media App!" << endl;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Create an Account" << endl;
        cout << "2. Login to Existing Account" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, email, password;
                cout << "Enter your name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter your email: ";
                cin >> email;
                cout << "Enter your password: ";

                // Masking the password input with asterisks
                #ifdef _WIN32
                char ch;
                password = "";
                while ((ch = _getch()) != '\r') {
                    cout << '*';
                    password += ch;
                }
                #else
                cin >> password;
                #endif

                cout << endl;

                cout << "Choose User Type:" << endl;
                cout << "1. Regular User" << endl;
                cout << "2. Business User" << endl;

                int userType;
                cin >> userType;

                if (userType == 1) {
                    RegularUser newUser(name, email, password);
                    regularUsers.push_back(newUser);
                    cout << "Regular User Account Created Successfully!" << endl;
                } else if (userType == 2) {
                    BusinessUser newUser(name, email, password);
                    businessUsers.push_back(newUser);
                    cout << "Business User Account Created Successfully!" << endl;
                } else {
                    cout << "Invalid choice!" << endl;
                }

                break;
            }

            case 2: {
                string email, password;
                cout << "Enter your email: ";
                cin >> email;
                cout << "Enter your password: ";

                // Masking the password input with asterisks
                #ifdef _WIN32
                char ch;
                password = "";
                while ((ch = _getch()) != '\r') {
                    cout << '*';
                    password += ch;
                }
                #else
                cin >> password;
                #endif

                cout << endl;

                bool found = false;

                for (auto& user : regularUsers) {
                    if (user.getEmail() == email && user.verifyPassword(password)) {
                        found = true;
                        cout << "Logged in as Regular User: " << user.getName() << endl;

                        int userChoice;
                        while (true) {
                            cout << endl;
                            cout << "\nUser Menu:" << endl;
                            cout << "1. Add Post" << endl;
                            cout << "2. Like Post" << endl;
                            cout << "3. Comment on Post" << endl;
                            cout << "4. View Feed" << endl;
                            cout << "5. View Profile" << endl;
                            cout << "6. Logout" << endl;

                            cout << "Enter your choice: ";
                            cin >> userChoice;

                            switch (userChoice) {
                                case 1: {
                                    string content;
                                    cout << "\nEnter post content: ";
                                    cin.ignore();
                                    getline(cin, content);
                                    user.addPost(content);
                                    cout << "Post added successfully!" << endl;
                                    break;
                                }

                                case 2: {
                                    int postId;
                                    cout << "\nEnter post ID to like: ";
                                    cin >> postId;
                                    if (postId >= 0 && postId < user.getFeedSize()) {
                                        user.likePost(*user.feed[postId]);
                                        cout << "Liked the post!" << endl;
                                    } else {
                                        cout << "Invalid post ID!" << endl;
                                    }
                                    break;
                                }

                               case 3: {
                                    int postId;
                                    cout << "\nEnter post ID to comment on: ";
                                    cin >> postId;
                                    if (postId >= 0 && postId < user.getFeedSize()) {
                                        string comment;
                                        cout << "Enter your comment: ";
                                        cin.ignore(); // Clear the input buffer
                                        getline(cin, comment);
                                        user.commentOnPost(*user.feed[postId], comment);
                                        cout << "Comment added successfully!" << endl;
                                    } else {
                                        cout << "Invalid post ID!" << endl;
                                    }
                                    break;
                                }

                                case 4:
                                    cout << endl;
                                    cout << endl;
                                    user.viewFeed();
                                    break;

                                case 5:
                                    cout << endl;
                                    cout << endl;
                                    user.viewProfile();
                                    break;

                                case 6:
                                    found = false;
                                    cout << "\nLogging out...." << endl;
                                    break;

                                default:
                                    cout << "Invalid choice!" << endl;
                            }

                            if (!found) {
                                break;
                            }
                        }

                        break;
                    }
                }

                if (!found) {
                    for (auto& user : businessUsers) {
                        if (user.getEmail() == email && user.verifyPassword(password)) {
                            found = true;
                            cout << "Logged in as Business User: " << user.getName() << endl;

                            int userChoice;
                            while (true) {
                                cout << endl;
                                cout << "\nUser Menu:" << endl;
                                cout << "1. Add Post" << endl;
                                cout << "2. Like Post" << endl;
                                cout << "3. Comment on Post" << endl;
                                cout << "4. View Feed" << endl;
                                cout << "5. Promote Post" << endl;
                                cout << "6. View Profile" << endl;
                                cout << "7. Logout" << endl;

                                cout << "Enter your choice: ";
                                cin >> userChoice;

                                switch (userChoice) {
                                    case 1: {
                                        string content;
                                        cout << "\nEnter post content: ";
                                        cin.ignore();
                                        getline(cin, content);
                                        user.addPost(content);
                                        cout << "Post added successfully!" << endl;
                                        break;
                                    }

                                    case 2: {
                                        int postId;
                                        cout << "\nEnter post ID to like: ";
                                        cin >> postId;
                                        if (postId >= 0 && postId < user.getFeedSize()) {
                                            user.likePost(*user.feed[postId]);
                                            cout << "Liked the post!" << endl;
                                        } else {
                                            cout << "Invalid post ID!" << endl;
                                        }
                                        break;
                                    }

                                    case 3: {
                                        int postId;
                                        cout << "\nEnter post ID to comment on: ";
                                        cin >> postId;
                                        if (postId >= 0 && postId < user.getFeedSize()) {
                                            string comment;
                                            cout << "Enter your comment: ";
                                            cin.ignore(); // Clear the input buffer
                                            getline(cin, comment);
                                            user.commentOnPost(*user.feed[postId], comment);
                                            cout << "Comment added successfully!" << endl;
                                        } else {
                                            cout << "Invalid post ID!" << endl;
                                        }
                                        break;
                                    }

                                    case 4:
                                        cout << endl;
                                        user.viewFeed();
                                        break;

                                    case 5: {
                                        int postId;
                                        cout << "\nEnter post ID to promote: ";
                                        cin >> postId;
                                        if (postId >= 0 && postId < user.getFeedSize()) {
                                            user.promotePost(*user.feed[postId]);
                                            cout << "Post promoted successfully!" << endl;
                                        } else {
                                            cout << "Invalid post ID!" << endl;
                                        }
                                        break;
                                    }

                                    case 6:
                                        cout << endl;
                                        user.viewProfile();
                                        break;

                                    case 7:
                                        found = false;
                                        cout << "\nLogged out successfully!" << endl;
                                        break;

                                    default:
                                        cout << "Invalid choice!" << endl;
                                }

                                if (!found) {
                                    break;
                                }
                            }

                            break;
                        }
                    }
                }

                else
                   cout << "Invalid email or password!" << endl;
            

                break;
            }

            case 3:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}


