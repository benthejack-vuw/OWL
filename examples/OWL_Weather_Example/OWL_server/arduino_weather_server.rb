require 'http'
require 'serialport'
require_relative 'OWL'


class SerialWeather

	def initialize
		@url = "http://api.openweathermap.org/data/2.5/weather?q=wellington,nz&APPID=83e124a7d0bf750b770c9919f05fac8c"
		puts @url
		@owl = OWL.new self
		@owl.run
	end

	def println args
		puts "arduino told me to say #{args[0]}"
	end

	def log args
		print args[0].chomp
	end

	def get_humidity args
		weatherData = JSON.parse(HTTP.get(@url).to_s)
		humidity = weatherData["main"]["humidity"]
		puts "got humidity: #{humidity}"
		@owl.write "get_humidity", humidity
	end

end

weather = SerialWeather.new
