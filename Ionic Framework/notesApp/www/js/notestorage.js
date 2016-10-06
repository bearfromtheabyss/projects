angular.module('mynotes.notestorage', [])
.factory('noteFactory', function(){
    var notes = angular.fromJson(window.localStorage['notes'] || '[]');

    function saveToLocalStorage()
    {
    	window.localStorage['notes'] = angular.toJson(notes);
    }


    return {
      list: function()
      {
        return notes;
      },
      get: function(ntnum)
      {
        for(var i = 0; i<=notes.length; i++)
        {
          if(notes[i].id === ntnum)
          {
            return notes[i];
          }
        }
        return undefined;
      },
      update: function(note)
      {
        for(var i = 0; i<=notes.length; i++)
        {
          if(note.id === notes[i].id)
          {
            notes[i] = note;
            saveToLocalStorage();
            return;
          }
        }

      },
      create: function(note)
      {
        notes.push(note);
        saveToLocalStorage();
      },
      delete: function(ntnum)
      {
      	 for(var i = 0; i<=notes.length; i++)
        {
          if(notes[i].id === ntnum)
          {
            notes.splice(i, 1);
            saveToLocalStorage();
            return;
          }
        }
        return undefined;
      },
      move: function(note, fromIndex, toIndex){
        $scope.notes.splice(fromIndex, 1);
        $scope.notes.splice(toIndex, 0, note);
        saveToLocalStorage();
      }
    }
  });