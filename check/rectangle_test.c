#include <rectangle.h>

#include <check.h>

START_TEST(test_area_with_width_1_height_1_is_1)
{
  Rectangle rectangle = Rectangle_New(1.0, 1.0);
  ck_assert(Rectangle_Area(rectangle) == 1.0);
}
END_TEST

START_TEST(test_area_with_width_2_height_3_is_6)
{
  Rectangle rectangle = Rectangle_New(2.0, 3.0);
  ck_assert(Rectangle_Area(rectangle) == 6.0);
}
END_TEST

START_TEST(test_perimeter_with_width_1_height_1_is_1)
{
  Rectangle rectangle = Rectangle_New(1.0, 1.0);
  ck_assert(Rectangle_Perimeter(rectangle) == 4.0);
}
END_TEST

START_TEST(test_perimeter_with_width_2_height_3_is_10)
{
  Rectangle rectangle = Rectangle_New(2.0, 3.0);
  ck_assert(Rectangle_Perimeter(rectangle) == 10.0);
}
END_TEST

START_TEST(test_is_square_when_width_1_height_1)
{
  Rectangle rectangle = Rectangle_New(1.0, 1.0);
  ck_assert(Rectangle_IsSquare(rectangle));
}
END_TEST

START_TEST(test_is_not_square_with_width_2_height_3)
{
  Rectangle rectangle = Rectangle_New(2.0, 3.0);
  ck_assert(!Rectangle_IsSquare(rectangle));
}
END_TEST

Suite *rectangle_suite(void)
{
  Suite *s = suite_create("Rectangle");

  TCase *tc_area = tcase_create("area");
  tcase_add_test(tc_area, test_area_with_width_1_height_1_is_1);
  tcase_add_test(tc_area, test_area_with_width_2_height_3_is_6);
  suite_add_tcase(s, tc_area);

  TCase *tc_perimeter = tcase_create("perimeter");
  tcase_add_test(tc_perimeter, test_perimeter_with_width_1_height_1_is_1);
  tcase_add_test(tc_perimeter, test_perimeter_with_width_2_height_3_is_10);
  suite_add_tcase(s, tc_perimeter);

  TCase *tc_is_square = tcase_create("isSquare");
  tcase_add_test(tc_is_square, test_is_square_when_width_1_height_1);
  tcase_add_test(tc_is_square, test_is_not_square_with_width_2_height_3);
  suite_add_tcase(s, tc_is_square);

  return s;
}
