#include <boost/test/unit_test.hpp>

#include "../src/paint/objects/cursor.hpp"
#include "../src/settings.hpp"

BOOST_AUTO_TEST_CASE(move_up)
{
    Cursor cursor(1, 2, 'f');
    cursor.moveUp();
    BOOST_CHECK(cursor.getX() == 1 && cursor.getY() == 1);
    
    cursor.moveUp();
    BOOST_CHECK(cursor.getX() == 1 && cursor.getY() == 1);
}

BOOST_AUTO_TEST_CASE(move_down)
{
    Cursor cursor(1, CANVAS_HEIGHT - 3, 'f');
    cursor.moveDown();
    BOOST_CHECK(cursor.getX() == 1 && cursor.getY() == CANVAS_HEIGHT - 2);
    
    cursor.moveDown();
    BOOST_CHECK(cursor.getX() == 1 && cursor.getY() == CANVAS_HEIGHT - 2);
}

BOOST_AUTO_TEST_CASE(move_left)
{
    Cursor cursor(2, 1, 'f');
    cursor.moveLeft();
    BOOST_CHECK(cursor.getX() == 1 && cursor.getY() == 1);
    
    cursor.moveLeft();
    BOOST_CHECK(cursor.getX() == 1 && cursor.getY() == 1);
}

BOOST_AUTO_TEST_CASE(move_right)
{
    Cursor cursor(CANVAS_WIDTH - 3, 1, 'f');
    cursor.moveRight();
    BOOST_CHECK(cursor.getX() == CANVAS_WIDTH - 2 && cursor.getY() == 1);
    
    cursor.moveRight();
    BOOST_CHECK(cursor.getX() == CANVAS_WIDTH - 2 && cursor.getY() == 1);
}