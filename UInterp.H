    
    // Find local flow velocity by interpolating to element location
    
    vector inflowVelocity(VGREAT, VGREAT, VGREAT);
    vector inflowVelocityPoint(0.1, 0.5, 0.2);
    label inflowCellI = mesh.findCell(inflowVelocityPoint);
    if (inflowCellI != -1)
    {
        Sout<< "\nProcessor " << Pstream::myProcNo() << " contains cell "
            << inflowCellI << endl << endl;
        
        inflowVelocity = UInterp.interpolate
        (
            inflowVelocityPoint, 
            inflowCellI
        );
        
        Sout<< "inflowVelocity: " << inflowVelocity << endl << endl;
    }
    else
    {
        Sout<< "Processor " << Pstream::myProcNo() 
            << " does not contain cell" << endl << endl;
    }
    
    if (false)
    {
        // Pick minimum value from from all processors
        reduce(inflowVelocity, minOp<vector>());
        
        Info<< "inflowVelocity: " << inflowVelocity << endl << endl;
    }
