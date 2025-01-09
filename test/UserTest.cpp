#include "gtest/gtest.h"
#include "../User.h"

TEST(UserTest, Getters) {
    const User user ("Eros", "Pinzani", "1234567890", "path/to/picture");
    ASSERT_EQ(user.getName(), "Eros" );
    ASSERT_EQ(user.getLastName(), "Pinzani" );
    ASSERT_EQ(user.getPhoneNumber(), "1234567890" );
    ASSERT_EQ(user.getProfilePicturePath(), "path/to/picture" );
}