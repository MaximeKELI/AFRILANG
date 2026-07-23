# Compile-fail / semantic expectation notes (not executed as .afr).
# Negative cases are covered by unit tests where the compiler must reject.

# expected: semantic error — onlyNumber where T is number, call with text
# function onlyNumber<T>(x T) returns T where T is number
#     return x
# end
# create bad = onlyNumber("x")
