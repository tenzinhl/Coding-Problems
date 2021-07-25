import React from 'react';
import ReactDOM from 'react-dom';
import './index.css'; // OK, so importing css files is a feature unique to WebPack, which create-react-app automatically uses
// See here: https://create-react-app.dev/docs/adding-a-stylesheet/
import App from './App';
import * as serviceWorker from './serviceWorker';

ReactDOM.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>,
  document.getElementById('root')
);

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: https://bit.ly/CRA-PWA
serviceWorker.unregister();

/* So I kind of already guessed/partially knew this, but there are a lot of build tools and other "things" (like
  React, Babel, wtf does JSX even count as) that are included and utilized when you use "create-react-app". This means
  seemingly fundamental things like syntax and structure ALL COULD BE FROM DIFFERENT TOOLS OR Languages
  other than the basic "Javascript, CSS, HTML" that you often think of with web-development. Important to keep
  that in mind, and it explains why basic things can feel insanely complicated. I am not alone. 
  Apparently once you learn these things, and you slowly add more tools to your toolkit, these different tools
  can greatly accelerate the development process.*/