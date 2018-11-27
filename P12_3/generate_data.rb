#!/usr/bin/env ruby

require 'Faker'

def is_numeric?(obj)
   obj.to_s.match(/\A[+-]?\d+?(\.\d+)?\Z/) == nil ? false : true
end

n = 200

args = ARGV;
argc = ARGV.size
if (argc >= 1 && is_numeric?(args[0]))
    n = args[0].to_i
end

dir = "/Users/christianmeyer/cpp/ch12/P12_3/"
file = dir + "data.txt"
if (argc >= 2)
    file = dir + args[1].to_s
end

endline = "\n";

File.open(file, 'w') {|f|
    Faker::Config.random.seed
    f.write(n, endline);
    n.times do
        x = 1 + rand(1000);
        f.write(x, "\n")
    end

}
