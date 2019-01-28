def factorial
    yield
end

print "Engine:   ", RUBY_ENGINE, ", Platform: ", RUBY_PLATFORM, ", Version:  ",RUBY_VERSION
puts ""

n = ARGV[0].to_i
factorial do 
    puts (1..n).reduce(:*)
end