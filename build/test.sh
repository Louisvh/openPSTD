#!/usr/bin/env bash

if [ ${TARGET} != "win64" ]; then
    if [ ${TRAVIS_OS_NAME} = "linux" ]; then
        DEPENDENCY_CHECKER=ldd
    else
        DEPENDENCY_CHECKER=otool\ -L
    fi

    echo Dependencies for OpenPSTD-gui
    ${DEPENDENCY_CHECKER} OpenPSTD-gui

    echo Dependencies for OpenPSTD-test
    ${DEPENDENCY_CHECKER} OpenPSTD-test

    echo "location: $PWD"
    ls -lAh

    ./OpenPSTD-test --log_format=XML --log_sink=results.xml --log_level=all --report_level=no --catch_system_errors=yes --build_info=yes -t DG,GUI
    RESULT=$?
    
    echo testing result: ${RESULT}

    xsltproc build/report/TestReport.xsl results.xml
    
    exit ${RESULT}
fi
