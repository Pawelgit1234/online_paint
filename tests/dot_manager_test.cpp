#include <boost/test/unit_test.hpp>

#include "../src/paint/objects/dot_manager.hpp"
#include "../src/settings.hpp"

BOOST_AUTO_TEST_CASE(add_dot)
{
    DotManager dotManager;

    Dot d(1, 1, Color::WHITE);
    dotManager.addDot(d);

    BOOST_CHECK_EQUAL(dotManager.getDots().size(), 1);

    Dot d2(1, 1, Color::RED);
    dotManager.addDot(d2);

    BOOST_CHECK_EQUAL(dotManager.getDots().size(), 1);
}