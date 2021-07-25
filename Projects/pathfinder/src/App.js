import React from 'react';
import './App.css';
import Pathfinder from './Pathfinder/Pathfinder.jsx';

function App() {
  return (
    <div className="App">
      <Pathfinder></Pathfinder>
    </div>
  );
}

export default App;

// So as I thought, Hidden in the React library, it looks for the index.html file, and react-scripts start opens
// that file, and uses it as the root. So when you use JSX "syntactic sugar" as they like to call it, the render()
// calls translate to Javascript getElementByID("root") in the index.html file.