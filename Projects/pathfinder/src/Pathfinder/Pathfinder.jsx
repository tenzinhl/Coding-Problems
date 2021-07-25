import React, {Component} from 'react';
import {Button, Navbar} from 'react-bootstrap';
import Node from './Node/Node';
import 'bootstrap/dist/css/bootstrap.css';

import './Pathfinder.css';
//import './styles.css';


const START_NODE_ROW = 10;
const START_NODE_COL = 15;
const FINISH_NODE_ROW = 10;
const FINISH_NODE_COL = 35;

export default class Pathfinder extends Component {
	constructor() {
		super();
		this.state = {
			grid: [],
			mouseIsPressed: false,
		};
	}

	componentDidMount() {
		const grid = getInitialGrid();
    this.setState({grid, mouseIsPressed: false});
	}

  handleMouseDown(row, col) {
    const newGrid = getNewWallGrid(this.state.grid, row, col);
    this.setState({grid: newGrid, mouseIsPressed: true});
  }

  //this handles "glitch" where clicking and dragging could be inconsistent if drag started in-between rows
  handleMouseDownGrid() {
    this.setState({mouseIsPressed: true});
  }
  handleMouseOver(row, col) {
    if (this.state.mouseIsPressed === true) {
      const newGrid = getNewWallGrid(this.state.grid, row, col);
      this.setState({grid: newGrid});
    }
  }
  handleMouseUp() {
    this.setState({mouseIsPressed: false})
  }
  //I find this hard to understand, esp. all the map() methods. Pay attention
  //to optional parameters section on MDN docs. map(callback function(current value, index, array, thisArg))

//below is quote from MDN that helps understand map. OMG this helps so much.
/*Consider:

["1", "2", "3"].map(parseInt)

While one might expect [1, 2, 3], the actual result is [1, NaN, NaN].

parseInt is often used with one argument, but takes two. The first is an expression and 
the second is the radix to the callback function, Array.prototype.map passes 3 arguments: (the element, the index, and the array)
*/
  render() {
    let grid = this.state.grid;
		return (
      <> 
      {/*cool new thing I learned. React return can normally only return one overall element (you can put
       multiple inside), but inside the <></> "a fragment" you can put multiple adjacent elements. Noice*/}
       <Navbar bg="dark" className="navbar">HELLO</Navbar>
        <Button onClick={() => this.componentDidMount()}>Reset Board</Button>
        <div 
          className="grid"
          onMouseDown={() => this.handleMouseDownGrid()}
          onMouseUp={() => this.handleMouseUp()}> {/* moved mouseUp event handler to grid to avoid
        glitch where you could let go of mouse in space between rows amd it wouldn't register
        hmm... sometimes when you drag it pulls an image of the rows? I figured out that when you click
        in-between the rows then try to click and drag it gets messed up. Maybe by moving handleMouseDown here
        we can fix it? Nope, it's messy. Maybe a separate method? LOL just looked at the video again, and it
        seems like a simpler, cleaner solution is just to format your grid so there aren't holes everywhere*/}
          {grid.map((row, rowIdx) => {
            return (
              /* HOLY FRICKING CRAP THIS FIXED IT THE ONDRAGSTART PREVENT DEFAULT SHIT AAHHH.*/
              <div key={rowIdx} 
                onDragStart={e => {
                  e.preventDefault();
                  e.stopPropagation();
                }}>
                {row.map((node, nodeIdx) => {
                  /*I don't understand this line. I assume it somehow assigns all of these values separately 
                  from the node component. Can you do something like this in c++? Surely it's in poor taste
                  -> Okay, figured it out on JS fiddle. The {} makes an object, and I guess part of the JS lang
                  is that it will match the key in the {} to have the value of the matching key in the object
                  on the other side of the assignment operator. */
                  const {row, col, isFinish, isStart, isWall} = node;
                    return (
                      <Node
                        key={nodeIdx}
                        row={row}
                        col={col}
                        isFinish={isFinish}
                        isStart={isStart}
                        isWall={isWall}
                        onMouseDown={(row, col) => this.handleMouseDown(row, col)}
                        onMouseOver={(row, col) => this.handleMouseOver(row, col)}
                        onMouseUp={() => this.handleMouseUp()}
                        ></Node>
                    );
                })}
              </div>
            );
          })}
        </div>
      </>
    );
  }
  //syntax for render works off of how grid is made of nested arrays
}
    
          

//Return grid which is an array of rows, where each row is an array of node components.
const getInitialGrid = () => {
	const grid = [];
	for (let row = 0; row < 20; row++) {
		const currentRow = [];
		for (let col = 0; col < 50; col++) {
			currentRow.push(createNode(col, row));
		}
		grid.push(currentRow);
	}
	return grid;
};

const getNewWallGrid = (grid, row, col) => {
  const newGrid = grid.slice();
  const node = newGrid[row][col];
  node.isWall = !node.isWall;
  return newGrid;
}
const createNode = (col, row) => {
  return {
    col, //I guess this automatically makes the string "col" a key and then will attach it to the value passed by the function?
    row,
    isStart: row === START_NODE_ROW && col === START_NODE_COL,
    isFinish: row === FINISH_NODE_ROW && col === FINISH_NODE_COL,
    isWall: false,
    distance: Infinity,
    isVisited: false,
    previousNode: null,
  };
};
