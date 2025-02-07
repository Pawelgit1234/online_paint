#include <boost/test/unit_test.hpp>

#include "../src/paint/objects/cursor_manager.hpp"
#include "../src/settings.hpp"

BOOST_AUTO_TEST_CASE(add_cursor)
{
    CursorManager cursorManager;

    Cursor cursor(1, 1, 'f');
    cursorManager.addCursor(cursor);

    BOOST_CHECK_EQUAL(cursorManager.getCursors().size(), 1);

    Cursor cursor2(3, 2, 'f');
    cursorManager.addCursor(cursor2);

    BOOST_CHECK_EQUAL(cursorManager.getCursors().size(), 1);
}