Feature: Console program "test"

  Scenario: Error missing arguments
    When I run `build/test`
    Then the exit status should not be 0
    Then the stderr should contain "ERROR: Missing arguments"

  Scenario: Error unknown parametr
    When I run `build/test -c`
    Then the exit status should not be 0
    Then the stderr should contain "invalid option"

  Scenario: Error invalid mode (key -m)
    When I run `build/test -m invalid`
    Then the exit status should not be 0
    Then the stderr should contain "ERROR: Invalid mode `invalid'"

  Scenario: Error missing mode (key -m)
    When I run `build/test -f path`
    Then the exit status should not be 0
    Then the stderr should contain "ERROR: Missing mode"

  Scenario: Error missing path (key -f) when checksum mode
    When I run `build/test -m checksum`
    Then the exit status should not be 0
    Then the stderr should contain "ERROR: Missing path"

  Scenario: Error missing path (key -f) when words mode
    When I run `build/test -m words -v word`
    Then the exit status should not be 0
    Then the stderr should contain "ERROR: Missing path"

  Scenario: Error missing word (key -f) when words mode
    When I run `build/test -m words -f path`
    Then the exit status should not be 0
    Then the stderr should contain "ERROR: Missing word"

  Scenario: Error open file
    When I run `build/test -m checksum -f invalipath`
    Then the exit status should not be 0
    Then the stderr should contain "ERROR: Can't open file"

  Scenario: help message
    When I run `build/test -h`
    Then the stdout should contain:
    """
    --------
    TODO
    --------
    """
  Scenario: Checksum mode
    When I run `build/test -m checksum -f test/fixtures/input.bin`
    Then the stdout should contain "262"

  Scenario: Words mode
    When I run `build/test -m words -f test/fixtures/input.txt -v hello`
    Then the stdout should contain "3"
