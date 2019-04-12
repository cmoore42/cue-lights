leftOffset = 15;
bottomOffset = 11.5;
switchWidth = 24;
switchHeight = 18;
switchVgap = 6;
switchHgap = 6;
holeRadius = 16.5/2;

/*
 * Panel needs to be wide enough for 2 switches side-by-side.
 * It also has to be wide enough for the width of the circuit
 * board that's going to mount behind it.  The Rev 2 board is
 * about 82.5 mm wide.  The formula below ends up at 84 mm.
 */
panelWidth = leftOffset + switchWidth + switchHgap + switchWidth + leftOffset;
panelHeight = bottomOffset + switchHeight + bottomOffset;
panelThickness = 3.175;

module hole(row, column) {
    /* Round Holes */
    xLoc = leftOffset + (row * (switchWidth + switchHgap)) + (switchWidth / 2);
    yLoc = bottomOffset + (column * (switchHeight + switchVgap)) + (switchHeight / 2);
    translate ([xLoc, yLoc, -2]) cylinder(6, holeRadius, holeRadius, false);    
}

difference() {
    cube ([panelWidth, panelHeight, panelThickness]);
    hole(0, 0);
    hole(1, 0);
}