add_test([=[HeapSortTest.TestSizeOneArray]=]  D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug/tests.exe [==[--gtest_filter=HeapSortTest.TestSizeOneArray]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HeapSortTest.TestSizeOneArray]=]  PROPERTIES WORKING_DIRECTORY D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[QuickSortTest.TestSizeOneArray]=]  D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug/tests.exe [==[--gtest_filter=QuickSortTest.TestSizeOneArray]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[QuickSortTest.TestSizeOneArray]=]  PROPERTIES WORKING_DIRECTORY D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[ShellSortTest.TestSizeOneArray]=]  D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug/tests.exe [==[--gtest_filter=ShellSortTest.TestSizeOneArray]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ShellSortTest.TestSizeOneArray]=]  PROPERTIES WORKING_DIRECTORY D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[InsertionSortTest.TestSizeOneArray]=]  D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug/tests.exe [==[--gtest_filter=InsertionSortTest.TestSizeOneArray]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[InsertionSortTest.TestSizeOneArray]=]  PROPERTIES WORKING_DIRECTORY D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  tests_TESTS HeapSortTest.TestSizeOneArray QuickSortTest.TestSizeOneArray ShellSortTest.TestSizeOneArray InsertionSortTest.TestSizeOneArray)
