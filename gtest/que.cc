#include <iostream>
#include <queue>
#include <gtest/gtest.h>
using namespace std;

template <typename E>
class Queue {
public:
    Queue() {
    }
    void Enqueue(const E& element) {
        E* temp = new E(element);
        que_.push(temp);
    }
    E* Dequeue() {
        if (que_.empty()) {
            return nullptr;
        } else {
            E* e = que_.front();
            que_.pop();
            return e;
        }
    }
    size_t Size() const {
        return que_.size();
    }
private:
    queue<E *> que_;
};

class QueueTest : public ::testing::Test {
protected:
    void SetUp() override {
        q1_.Enqueue(1);
        q2_.Enqueue(2);
        q2_.Enqueue(3);
    }
    Queue<int> q0_;
    Queue<int> q1_;
    Queue<int> q2_;
};

TEST_F(QueueTest, IsEmptyInitially) {
    EXPECT_EQ(q0_.Size(), 0);
}
TEST_F(QueueTest, DequeueWorks) {
    int* n = q0_.Dequeue();
    EXPECT_EQ(n, nullptr);

    n = q1_.Dequeue();
    EXPECT_EQ(*n, 1);
    EXPECT_EQ(q1_.Size(), 0);
    delete n;
    
    n = q2_.Dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(*n, 2);
    EXPECT_EQ(q2_.Size(), 1);
    delete n;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
