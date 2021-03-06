project(libecl-applications)

if (NOT BUILD_APPLICATIONS)
    return ()
endif ()

add_executable(sum_write   ecl/sum_write.c)
add_executable(make_grid   ecl/make_grid.c)
add_executable(grdecl_grid ecl/grdecl_grid.c)
add_executable(summary     ecl/view_summary.c)
target_link_libraries(sum_write     ecl)
target_link_libraries(make_grid     ecl)
target_link_libraries(grdecl_grid   ecl)
target_link_libraries(summary       ecl)

list(APPEND apps make_grid grdecl_grid summary)

foreach (app ecl_pack
             ecl_unpack
             kw_extract
             grid_info
             grid_dump
             grid_dump_ascii
             select_test
             load_test
        )
    add_executable(${app} ecl/${app}.c)
    target_link_libraries(${app} ecl ert_util)
    list(APPEND apps ${app})
    if (ERT_LINUX)
        # The stupid .x extension creates problems on windows
        set_target_properties(${app} PROPERTIES SUFFIX ".x")
    endif ()
endforeach ()


if (ERT_LINUX)
    foreach (app convert esummary grdecl_test kw_list)
        add_executable(${app} ecl/${app}.c)
        target_link_libraries(${app} ecl ert_util)
        # The stupid .x extension creates problems on windows
        set_target_properties(${app} PROPERTIES SUFFIX ".x")
        list(APPEND apps ${app})
    endforeach ()

    set_target_properties(summary PROPERTIES SUFFIX ".x")
endif ()


if (BUILD_ERT)
    add_executable( ecl_quantile ecl/ecl_quantile.c )
    target_link_libraries( ecl_quantile config )
    list(APPEND apps ecl_quantile)
endif()

if (BUILD_ECL_SUMMARY)
   add_executable(ecl_summary ecl/view_summary.c)
   target_link_libraries(ecl_summary ecl)
   list(APPEND apps ecl_summary)

   install(FILES ${PROJECT_SOURCE_DIR}/man/man1/ecl_summary.1
           DESTINATION ${CMAKE_INSTALL_MANDIR}/man1)
endif()

if (PTHREAD_LIBRARY)
    add_executable(bls block_fs/bls.c)
    target_link_libraries(bls ert_util)
    list(APPEND apps bls)
endif ()

add_executable(segment_info well/segment_info.c)
add_executable(CF_dump      well/well_CF_dump.c)
add_executable(ri_well_test well/ri_well_test.c)

target_link_libraries(segment_info ecl_well)
target_link_libraries(CF_dump ecl_well)
target_link_libraries(ri_well_test ecl_well)

list(APPEND apps segment_info CF_dump ri_well_test)

install(TARGETS ${apps}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
