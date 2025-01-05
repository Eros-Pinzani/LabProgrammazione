#include "gtest/gtest.h"
#include "../User.h"

TEST(UserTest, GetName) {
    User user ("Eros");
    ASSERT_EQ(user.getName(), "Eros" );
}