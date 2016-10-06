var weatherForecast = angular.module('weatherForecast', ['ngRoute', 'ngResource']);
//ROUTES
weatherForecast.config(function($routeProvider) {
	$routeProvider.
		when('/', {
			templateUrl: 'pages/home.html',
			controller: 'mainController'	
		}).
		when('/forecast', {
			templateUrl: 'pages/forecast.html',
			controller: 'forecastController'
		}).
		when('/forecast/:count', {
			templateUrl: 'pages/forecast.html',
			controller: 'forecastController'
		})
});
//SERVICES

weatherForecast.service('cityForecast', function(){
	this.city = "Warsaw, POL";
	this.count = 2;
});



//CONTROLLERS
weatherForecast.controller('mainController', ['$scope', '$location', 'cityForecast', function($scope, $location, cityForecast){
	$scope.city = cityForecast.city;
	$scope.count = cityForecast.count;
	$scope.$watch('city', function() 
	{
		cityForecast.city = $scope.city;
		
	});
	$scope.$watch('count', function(){
		cityForecast.count = $scope.count;
	});
	$scope.submit = function(){
		$location.path("/forecast")
	};
}]);

weatherForecast.controller('forecastController', ['$scope', '$resource', '$routeParams' ,'cityForecast', function($scope, $resource, $routeParams, cityForecast){
	$scope.city = cityForecast.city;
	$scope.count = $routeParams.count || 4;
	$scope.weatherAPI = $resource('http://api.openweathermap.org/data/2.5/forecast/daily?APPID=2672a48f032788baa8a38329bd7df713', 
	{callback: "JSON_CALLBACK"},{get: {method: "JSONP"}});

	$scope.weatherResult = $scope.weatherAPI.get({q: $scope.city, cnt: $scope.count});

	$scope.convertToCelcius = function(degK)
	{
		var temp = degK-273.15;
		var filteredTemp = temp.toPrecision(3);
		return filteredTemp;
	}
	$scope.convertToDate = function(dt)
	{
		return new Date(dt * 1000);
	}	
	$scope.checkIfPositive = function(val){
		if(val > 0)
		{
			return val;
		}
		else
			return 0;
	}

}]);

//DIRECTIVES
weatherForecast.directive("weatherReport", function(){
	return {
		restrict: 'E',
		templateUrl: 'templates/weatherReport.html',
		replace: true,
		scope: {
			weatherDay: "=",
			convertToStandard: "&",
			convertToDate: "&",
			dateFormat: "@",
			checkIfZero: "&"
		}
	}

});