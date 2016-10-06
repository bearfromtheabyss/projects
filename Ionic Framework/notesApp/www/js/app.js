(function(){

  var app = angular.module('noteApp', ['ionic', 'mynotes.notestorage']);

  app.config(function($stateProvider, $urlRouterProvider) {

    $stateProvider.state('home', {
     url: '/home' ,
     templateUrl: 'pages/home.html',
     controller: 'noteController'
   });

    $stateProvider.state('add', {
     url: '/add' ,
     templateUrl: 'pages/edit.html',
     controller: 'addController'
   });

    $stateProvider.state('edit', {
     url: '/edit/:num' ,
     templateUrl: 'pages/edit.html',
     controller: 'editController'
   });

    $urlRouterProvider.otherwise('/home');

  });

  app.controller('noteController', ['$scope', 'noteFactory', function($scope, noteFactory){
    $scope.notes = noteFactory.list();
    $scope.delete = function(ntnum)
    {
      noteFactory.delete(ntnum);
    }
    $scope.move = function(note, fromIndex, toIndex){
        noteFactory.move(note, fromIndex, toIndex);
        
    }
    $scope.toggle = false;
    $scope.toggleReordering = function()
    {
      $scope.toggle = !$scope.toggle;
    }
  }]);


  app.controller('addController', ['$scope', '$state', 'noteFactory', function($scope, $state, noteFactory){
    $scope.note = {id: new Date().getTime().toString(), title: '', desc: ''};
    $scope.save = function()
    {
      noteFactory.create($scope.note);
      $state.go('home');
    };
  }]);

  app.controller('editController', ['$scope', '$state', 'noteFactory', function($scope, $state, noteFactory){
    $scope.note = angular.copy(noteFactory.get($state.params.num));
    $scope.save = function()
    {
      noteFactory.update($scope.note);
      $state.go('home');
    };
  }]);

  app.run(function($ionicPlatform) {
    $ionicPlatform.ready(function() {
      if(window.cordova && window.cordova.plugins.Keyboard) {
        cordova.plugins.Keyboard.hideKeyboardAccessoryBar(true);
        cordova.plugins.Keyboard.disableScroll(true);
      }
      if(window.StatusBar) {
        StatusBar.styleDefault();
      }
    });
  })
}())