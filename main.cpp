#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//need to create node struc for linked list
struct ReviewNode {
    float rating;
    string comment;
    ReviewNode* next;
};

//class to store review and ratings
class Movie {
    private:
        string title;
        ReviewNode* head; //head pointer for linked list of revciew

    public:
        Movie(const string& title) : title(title), head(nullptr){}
        //add method to adda review *rating/comment
        void addReview(float rating, const string& comment){
            ReviewNode* newNode = new ReviewNode;
            newNode-> rating = rating;
            newNode->comment = comment;
            newNode-> next = head; //add to head of list
            head = newNode;
        }

        //method to output review and average rating
        void outputReviews() const {
            ReviewNode* temp = head;
            int count = 1;
            float sum = 0.0;
            int reviewCount = 0;

            cout << "Reviews for \"" <<title << "\":\n";
            while (temp != nullptr) {
                cout << " Review #" << count << ": "<< fixed << setprecision(1)
                    <<temp->rating << "-" << temp-> comment << endl;
            sum += temp->rating;
            reviewCount++;
            temp = temp-> next;
            count++;
        }
        if (reviewCount > 0) {
            cout << " > Average Rating:" << fixed << setprecision(2)
                 << sum / reviewCount << "\n\n"
         else {
            cout << " > No reviews available.\n\n";
        }
    }
};

//func to gen random ratings between 1.0 and 5.0(1 dec. place)
float generateRandomRating(){
    return static_cast<float>((rand()% 41 +10))/10.0; //random #
}
//now we need a func to read review comments from an extternal file
vector<string> readCommentsFromFile(const string& filename) {
    vector<string> comments;
    ifstream file(filename);

    if(!file) {
        cerr<< "error opening file:" << filename << endl;
        return comments;
    }
    string line;
    while (getline(file,line)){
        if (!line.empty()){
            comments.push_back(line);
        }
    }
    file.close();
    return comments;
}
int main () {
    srand(static_cast<unsigned>(time(0))); //to seed random number gen

    //read review comm from file\
    vector<string> comments = readCommentsFromFile("review.txt");  
}

//now create two movies( i am going to use my favorites)

Movie movie1("The Shawshank Redemption");
Movie movie2("The Godfather");

//reviews to movies, add
movie1.addReview(generatorRandomRating(), comments[0]);
movie1.addReview(generatorRandomRating(), comments[1]);

movie2.addReview(generatorRandomRating(), comments[2]);
movie2.addReview(generatorRandomRating(), comments[3]);

//output review
movie1.outputReviews();
movie2.outoutReviews();

return 0;

}