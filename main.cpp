// Title: Movie Review System
// Description: A program to store and manage movie reviews using linked lists.
//              Each movie has a linked list for ratings and comments.
//              Reviews are read from an external file and ratings are random.
// Author: Talha Ahmed
// Lab: 19
// Class: COMSC-210

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Node structure for linked list
struct ReviewNode {
    float rating;
    string comment;
    ReviewNode* next;
};

// Movie class to store reviews and ratings
class Movie {
private:
    string title;
    ReviewNode* head;  // Head pointer for the linked list of reviews

public:
    Movie(const string& title) : title(title), head(nullptr) {}

    // Method to add a review (rating and comment)
    void addReview(float rating, const string& comment) {
        ReviewNode* newNode = new ReviewNode;
        newNode->rating = rating;
        newNode->comment = comment;
        newNode->next = head;  // Add to the head of the list
        head = newNode;
    }

    // Method to output reviews and average rating
    void outputReviews() const {
        ReviewNode* temp = head;
        int count = 1;
        float sum = 0.0;
        int reviewCount = 0;

        cout << "Reviews for \"" << title << "\":\n";
        while (temp != nullptr) {
            cout << "  > Review #" << count << ": " << fixed << setprecision(1) 
                 << temp->rating << " - " << temp->comment << endl;
            sum += temp->rating;
            reviewCount++;
            temp = temp->next;
            count++;
        }

        if (reviewCount > 0) {
            cout << "  > Average Rating: " << fixed << setprecision(2) 
                 << sum / reviewCount << "\n\n";
        } else {
            cout << "  > No reviews available.\n\n";
        }
    }
};

// Function to generate random ratings between 1.0 and 5.0 (1 decimal place)
float generateRandomRating() {
    return static_cast<float>((rand() % 41 + 10)) / 10.0;  // Random between 1.0 and 5.0
}

// Function to read review comments from an external file
vector<string> readCommentsFromFile(const string& filename) {
    vector<string> comments;
    ifstream file(filename);

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return comments;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            comments.push_back(line);
        }
    }

    file.close();
    return comments;
}

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed the random number generator

    // Read review comments from file (assumes 'reviews.txt' exists with comments)
    vector<string> comments = readCommentsFromFile("reviews.txt");
    if (comments.empty()) {
        cerr << "No comments available to add reviews.\n";
        return 1;
    }

    // Create two movies
    Movie movie1("The Shawshank Redemption");
    Movie movie2("The Godfather");

    // Adding reviews to movie1
    movie1.addReview(generateRandomRating(), comments[0]);
    movie1.addReview(generateRandomRating(), comments[1]);

    // Adding reviews to movie2
    movie2.addReview(generateRandomRating(), comments[2]);
    movie2.addReview(generateRandomRating(), comments[3]);

    // Output reviews for each movie
    movie1.outputReviews();
    movie2.outputReviews();

    return 0;
}
