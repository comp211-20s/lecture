#!/bin/bash

script_dir=$(dirname $(realpath "${0}"))
project_dir=$(realpath "${script_dir}/../../..")
bin_dir=${project_dir}/build/bin
build_dir=${project_dir}/build/test/integration
tests_dir=${project_dir}/test/integration

bats_dir="${build_dir}/bats"
bats="${bats_dir}/bin/bats"
tests=$(ls "${tests_dir}" | grep '.bats')

main() {
    init
    link
    run-tests
}

init() {
    if [ ! -d "${build_dir}" ]; then
        mkdir -p "${build_dir}"
    fi

    # Link to bins in bin directory
    # bins=$(ls "${bin_dir}")
    # for bin in $bins; do
    #     if [ ! -e "${build_dir}/${bin}" ]; then
    #         ln -s "${bin_dir}/${bin}" "${build_dir}/${bin}"
    #     fi
    # done
    if [ ! -e "${build_dir}/bin" ]; then
        ln -s "${bin_dir}" "${build_dir}/bin"
    fi

    if [ ! -e "${build_dir}/preamble.bash" ]; then
        ln -s "${script_dir}/preamble.bash" "${build_dir}/preamble.bash"
    fi

    cd "${build_dir}"

    # Clone BATS and dependencies
    if [ ! -d "${bats_dir}" ]; then
        git clone --depth=1 https://github.com/sstephenson/bats
    fi

    if [ ! -d "${build_dir}/bats-assert" ]; then
        git clone --depth=1 https://github.com/ztombol/bats-assert
    fi

    if [ ! -d "${build_dir}/bats-support" ]; then
        git clone --depth=1 https://github.com/ztombol/bats-support
    fi
}

link() {
    for bats_test in $tests; do
        src="${tests_dir}/${bats_test}"
        dst="${build_dir}/${bats_test}"
        if [ ! -f "${dst}" ]; then
            ln -s "${src}" "${dst}"
        fi
    done
}

run-tests() {
    cd "${build_dir}"
    ${bats} *.bats
}

main
