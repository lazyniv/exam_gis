When(/I'm run `([^`]*)`/) do |cmd|
  @stdout = `#{cmd}`.chomp
  fail "#{cmd} exit with non zero status" unless $?.success?
end

Then("a stdout should contain:") do |expected|
  fail "Expected <#{expected}> but was <#{@stdout}>" unless\
    @stdout == expected
end
