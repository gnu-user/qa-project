/**
 * Swift Ticket -- Back End
 *
 * Copyright (C) 2013, Jonathan Gillett, Daniel Smullen, and Rayan Alfaheid
 * All rights reserved.
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedHashMap;

public class DailyTransactions
{
    private ArrayList<String> mergedTransactions;
    private LinkedHashMap<Transaction, String> transactions;
    private String dtfDirectory;


    /**
     * 
     * @param dtfDirectory
     * @throws FatalError 
     */
    public DailyTransactions(String dtfDirectory) throws FatalError
    {
        File directory = new File(dtfDirectory);

        if (directory.exists() && directory.isDirectory())
        {
            this.dtfDirectory = dtfDirectory;
            this.mergedTransactions = new ArrayList<String>();
            this.transactions = new LinkedHashMap<Transaction, String>();
            
            /* Merge the daily transaction files */
            merge();
            
            /* Parse the merged transactions */
            //parse();
        }
        else
        {
            throw new FatalError(ExceptionCodes.DTF_DIR_FOUND, dtfDirectory);
        }
    }

    public LinkedHashMap<Transaction, String> getTransactions()
    {
        return transactions;
    }
    
    public void displayTransactions()
    {
        for (String transaction : mergedTransactions)
        {
            System.out.println(transaction);
        }
    }
    
    /**
     * Merges the collection of all daily transaction files (*.dtf)
     * into a single array containing each transaction as a line.
     * 
     * @throws FatalError 
     */
    private void merge() throws FatalError
    {
        BufferedReader reader;
        String line;
        
        /* Merge each of the daily transaction files */
        for (File file : new File(dtfDirectory).listFiles())
        {
            if (file.getName().matches("^.+\\.dtf$"))
            {
                try
                {
                    reader = new BufferedReader(new FileReader(file));
                }
                catch (FileNotFoundException e1)
                {
                    e1.printStackTrace();
                    throw new FatalError(ExceptionCodes.DTF_NOT_FOUND, file.getPath());
                }

                try
                {
                    while ((line = reader.readLine()) != null)
                    {                        
                        /* If the DTF entry is valid add it to the merged list of transactions */
                        if (Validate.dtfEntry(line))
                        {
                            mergedTransactions.add(line.trim());
                        }
                        else
                        {
                            throw new FatalError(ExceptionCodes.CORRUPT_DTF, file.getCanonicalPath());
                        }
                    }
                    reader.close();
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                    throw new FatalError(ExceptionCodes.CORRUPT_DTF, file.getPath());
                }
                finally
                {
                    try
                    {
                        if (reader != null)
                        {
                            reader.close();
                        }
                    }
                    catch (IOException ex)
                    {
                        ex.printStackTrace();
                        throw new FatalError(ExceptionCodes.CORRUPT_DTF, file.getPath());
                    }
                }
            }
        }
    }

    private void parse()
    {
        throw new UnsupportedOperationException();
    }

}