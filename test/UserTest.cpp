#include "gtest/gtest.h"
#include "../User.h"

TEST(UserTest, Getters) {
    const User user ("Eros", "Pinzani", "1234567890", "path/to/picture");
    ASSERT_EQ(user.getName(), "Eros" );
    ASSERT_EQ(user.getLastName(), "Pinzani" );
    ASSERT_EQ(user.getPhoneNumber(), "1234567890" );
    ASSERT_EQ(user.getProfilePicturePath(), "path/to/picture" );
}

TEST(UserTest, EmptyContent) {
    EXPECT_THROW(const User user ("", "Pinzani", "1234567890", "path/to/picture");, std::invalid_argument);
    EXPECT_THROW(const User user ("Eros", "", "1234567890", "path/to/picture");, std::invalid_argument);
    EXPECT_THROW(const User user ("Eros", "Pinzani", "", "path/to/picture");, std::invalid_argument);
    EXPECT_THROW(const User user ("Eros", "Pinzani", "1234567890", "");, std::invalid_argument);
    EXPECT_THROW(const User user ("", "", "", "");, std::invalid_argument);
}