require 'http'
require 'serialport'
require_relative 'OWL'


class SerialTime

	def initialize
		@owl = OWL.new self, 115200
		@owl.run
	end

	def println args
		puts "arduino told me to say #{args[0]}"
	end

	def log args
		print args[0].chomp
	end

	def get_hours args
		hours = Time.now().hour
		@owl.write "get_hours", hours
	end

	def get_minutes args
		minutes = Time.now().min
		@owl.write "get_minutes", minutes
	end

	def get_seconds args
		seconds = Time.now().sec
		@owl.write "get_seconds", seconds
	end

	def get_millis args
		millis = Time.now().strftime("%L")
		@owl.write "get_millis", millis
	end

end

time = SerialTime.new
