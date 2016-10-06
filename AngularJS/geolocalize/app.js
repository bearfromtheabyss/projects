var geoConn = angular.module('geoConn', ['ngMap', 'ngResource', 'ngRoute']);

geoConn.service('updateMap', function(){
	
	this.lng = 0;
	this.lat = 0;
	
});

geoConn.service('updateIp', function(){
	this.ip = "facebook.com";
});

geoConn.config(function($routeProvider) {

	$routeProvider.
		when('/', {
			templateUrl: 'pages/home.html',
			controller: 'mainController'
		})
		.when('/result.html', {
			templateUrl: 'pages/result.html',
			controller: 'mainController'
		})
	
});


geoConn.controller('mainController', ['$scope', '$window', 'updateMap', 'updateIp', '$resource', function($scope, $window, updateMap, updateIp, $resource){
	$scope.ip = updateIp.ip;
	navigator.geolocation.getCurrentPosition(function(position) {
		$scope.$apply(function(){
			$scope.lati = position.coords.latitude;
			$scope.lngt = position.coords.longitude;
		});
	});

	$scope.$watch('lngt', function() {
		 updateMap.lng = $scope.lngt;
	});
	$scope.$watch('lati', function() {
		updateMap.lat = $scope.lati;
	});

	$scope.$watch('ip', function(){
		updateIp.ip = $scope.ip;
	});

	$scope.geoIp = $resource('http://freegeoip.net/json/' + $scope.ip, {callback: "JSON_CALLBACK"},{get: {method: "JSONP"}});

	$scope.geoResult = $scope.geoIp.get({q: $scope.ip});

	console.log($scope.geoResult);

}]);