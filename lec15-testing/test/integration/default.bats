load preamble

# Testing Library: https://github.com/ztombol/bats-assert

@test "Integration Test Example" {
    run lec15-testing
    assert_success
}
