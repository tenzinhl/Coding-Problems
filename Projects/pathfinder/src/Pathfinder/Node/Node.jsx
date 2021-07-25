import React, {Component} from 'react';

import './Node.css';

export default class Node extends Component {
  render() {
    const {
      row,
      col,
      isFinish,
      isStart,
      isWall,
      onMouseDown,
      onMouseOver,
    } = this.props;
    const extraClassName = isFinish
      ? 'node-finish'
      : isStart
      ? 'node-start'
      : isWall
      ? 'node-wall'
      : '';
    
    return (
      <div
        id={`node-${row}-${col}`} //I guess you need the brackets since string insertion is a Javascript thing
        //also the reason this isn't working is because I goofed it by using single quotes and not back-ticks.
        //Why is it like this? who tf knows lol. apparently back ticks make it a template literal instead of a string.
        className={`node ${extraClassName}`}
        onMouseDown={() => onMouseDown(row, col)}
        onMouseOver={() => onMouseOver(row,col)}
      ></div>    
    );
  }
}