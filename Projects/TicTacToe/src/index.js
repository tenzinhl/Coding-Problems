import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';

function Square(props) {
  return(
    <button className="square" onClick={props.onClick}>
      {props.value}
    </button>
  )
}
  
  class Board extends React.Component {
    renderSquare(i) {
      return (
        <Square
          value={this.props.squares[i]}
          onClick={() => this.props.onClick(i)}
        />
      );
    }
    
    createBoard() {
      let board = [];

      //outer loop for parent?? oooh, I think I'm starting to see what they mean?
      //like you need a second array to hold the elements of each row, but their 
      //explanation doesn't clarify that at all.
      for (let i = 0; i < 3; i++) {
        let row = [];
        for (let j = 0; j < 3; j++) {
          row.push(this.renderSquare(i * 3 + j));
        }
        board.push(<div className="board-row"> {row} </div>)
        //inner loop to create children??? idk what this means

        /*for each loop you need a separate array... because with how the JSX language
        //is set up, you cannot insert code inside of a JSX html element (remember
        //that it's JSX is just a way to make code pretty, but JSX html elements
        //end up becoming react.createElement methods, so you couldn't just insert more
        // code in-between. (that would mean passing html elements into the React.createElement method
        which doesn't work) So no code in elements, BUT you can insert REACT ELEMENT variables... hmm...
        actually now that I've clarified this it seems weird that it doesn't work (since the react.createElement
        method should just produce a reace element variable (which is what we insert). Oh well, the point
        is that the somewhere in the pre-processor and react library pipeline, this isn't allowed!
        //so the idea is to create an array with the innermost loop, then in the outermost
        //loop insert that array each time. I think this is the only way to do nested 
        //loops. For single loops there is a way to use array.map() but WAYTOODANK for me. 
        I hate the explanation in the blog post. Doesn't understand my issue
        with understanding the problem. Probably didn't come from a c++ background tbf*/
      }
      return (<div>{board}</div>); //LOL I think I added unnecessary curly braces here. This may be the source of the issue HOLY FUCKING SHIT LETS GOO
    } //now there are curly braces. But if there was no JSX <div> stuff, you must not add braces for it to work. Weird huh.
    render() {
      return (
        // <div>
        //   <div className="board-row">
        //     {this.renderSquare(0)}
        //     {this.renderSquare(1)}
        //     {this.renderSquare(2)}
        //   </div>
        //   <div className="board-row">
        //     {this.renderSquare(3)}
        //     {this.renderSquare(4)}
        //     {this.renderSquare(5)}
        //   </div>
        //   <div className="board-row">
        //     {this.renderSquare(6)}
        //     {this.renderSquare(7)}
        //     {this.renderSquare(8)}
        //   </div>
        // </div>
        this.createBoard() //hmmm... seems like you need the div in this statement, and it can't be in the function one??? OH fixed it! NOW you place curly brackets around "board" so div doesn't need to be here, but it's important to know when to curly brace and when not to
      );
    }
  }
  
  class Game extends React.Component {
    constructor(props) {
      super(props);
      this.state = {
        history: [{ //"[{ }]" represents an array of objects. Object type is defined inside {}... nvm. JS arrays can hold many different types at the same time.
          squares: Array(9).fill(null),
        }],
        mhistory: [1],
        stepNumber: 0,
        xIsNext: true,
      }
    }

    handleClick(i) {
      const history = this.state.history.slice(0, this.state.stepNumber + 1);
      const mhistory = this.state.mhistory.slice(0, this.state.stepNumber + 1);
      const current = history[history.length - 1];
      const squares = current.squares.slice();
      if (calculateWinner(squares) || squares[i]) {
        return;
      }
      squares[i] = this.state.xIsNext ? 'X' : 'O';
      this.setState({
        history: history.concat([{ //look into whether [] is necessary
          squares: squares,
        }]),
        mhistory: mhistory.concat(i),
        stepNumber: history.length,
        xIsNext: !this.state.xIsNext,
      });
    }

    jumpTo(step) {
      this.setState({
        stepNumber: step,
        xIsNext: (step % 2) === 0,
      });
    }
    //currently trying to resolve weird issue where first click will return Nan,Nan as position, but all subseuquent clicks work as desired
    //i'm guessing it's because sid is null when the first one runs.. but why does it work for the others still?
    //weird, initializing mhistory with a first null value fixed it???? WTF??? I didn't even have to change array indexes???
    //must be some hidden behavior of concatenate, it ignores null entries or something. SCREW THESE PEOPLE TRYING TO OVERSIMPLIFY SHIT.
    //nvm, unscrew those people and apologize. It works even if I put 1 as the initial value. I AM SO CONFUSEDDDD.
    //So first off, var moves was starting at 1, not zero, since the history already starts with one value so the first move
    //will have index of one. Secondly, I think slice() will append null values if you go outside the range of the array
    //so after the first handleClick, all future ones will be on track. Damn....
    render() {
      const history = this.state.history;
      const current = history[this.state.stepNumber];
      const winner = calculateWinner(current.squares);

      const moves = history.map((step, move) => {
        const sid = this.state.mhistory[move]; 
        const x = sid % 3 + 1;
        const y = Math.floor(sid / 3) + 1;
        const pos = ' (' + x + ', ' + y + ')'
        var desc = move ?
          'Go to move #' + move + pos :
          'Go to game start';
        return(
          <li key={move}>
            <button 
              style={(this.state.stepNumber === move) ? { fontWeight: 'bold' } : { fontWeight: 'normal' }} 
              onClick={() => this.jumpTo(move)}>{desc}</button>
          </li>
        );
      });

      let status;
      if (winner) {
        status = 'Winner: ' + winner;
      } else {
        status = 'Next player: ' + (this.state.xIsNext ? 'X' : 'O');
      }

      return (
        <div className="game">
          <div className="game-board">
            <Board
              squares={current.squares}
              onClick={(i) => this.handleClick(i)}
              board={this.state.board}
            />
          </div>
          <div className="game-info">
            <div>{status}</div>
            <ol>{moves}</ol>
          </div>
        </div>
      );
    }
  }
  
  // ========================================
  
  ReactDOM.render(
    <Game />,
    document.getElementById('root')
  );
  
  function calculateWinner(squares) {
    const lines = [ //this hardcodes all the possible winning positions
      [0, 1, 2],
      [3, 4, 5],
      [6, 7, 8],
      [0, 3, 6],
      [1, 4, 7],
      [2, 5, 8],
      [0, 4, 8],
      [2, 4, 6],
    ];
    for (let i = 0; i < lines.length; i++) { //iterates through each of the triplets in "lines"
      const [a, b, c] = lines[i];
      if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) { 
        return squares[a]; //checks value in first square (x or o) and then compares it to next two in triplet. 
        //If all match, value of first square (x or o) is returned as winner
      }
    }
    return null; //if no winner found, return null.
  }