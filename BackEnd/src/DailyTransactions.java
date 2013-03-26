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
import java.util.Arrays;
import java.util.Comparator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class DailyTransactions
{
    private ArrayList<String> mergedTransactions;
    private ArrayList<Transaction> transactions;
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
            this.transactions = new ArrayList<Transaction>();
            
            /* Merge the daily transaction files */
            merge();
            
            /* Parse the merged transactions */
            parse();
        }
        else
        {
            throw new FatalError(ExceptionCodes.DTF_DIR_FOUND, dtfDirectory);
        }
    }

    public ArrayList<Transaction> getTransactions()
    {
        return transactions;
    }
    
    public void displayTransactions()
    {
        for (Transaction transaction : transactions)
        {
            System.out.println(transaction.getTransaction());
        }
    }
    
    /**
     * Sorts an array of files by date modified in descending order,
     * the oldest modified file is the first in the resulting array.
     * 
     * @param files
     * @return
     */
    private void sortModified(File[] files)
    {
        Arrays.sort(files, new Comparator<File>(){
            public int compare(File file1, File file2)
            {
                return Long.valueOf(file1.lastModified()).compareTo(file2.lastModified());
            } }); 
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
        File[] files = new File(dtfDirectory).listFiles();
        
        /* Sort the files by modified date, the older modified file is processed first */
        sortModified(files);
        
        /* Merge each of the daily transaction files */
        for (File file : files)
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

    /**
     * @throws FatalError
     */
    private void parse() throws FatalError
    {
        /* Get the transaction code */
        Pattern reCode = Pattern.compile("^([0-9]{2})_.*$");
        
        /* Daily transaction entry matches logout, create, delete, or addcredit */
        Pattern reUserMod = Pattern.compile("^(00|01|02|06)_([A-Za-z0-9_]{1,15}?)_+(AA|FS|BS|SS)_([0-9]{6}\\.[0-9]{2})$");

        /* Daily transaction entry matches refund */
        Pattern reRefund = Pattern.compile("^(05)_([A-Za-z0-9_]{1,15}?)_+([A-Za-z0-9_]{1,15}?)_+([0-9]{6}\\.[0-9]{2})$");

        /* Daily transaction entry matches buy or sell */
        Pattern reBuySell = Pattern.compile("^(03|04)_(.{1,19}?)_+_([A-Za-z0-9_]{1,15}?)_+([0-9]{3})_([0-9]{3}\\.[0-9]{2})$");

        Matcher match;
        
        /* Parse each entry in the merged transactions */
        for (String entry : mergedTransactions)
        {
            /* Get the transaction code and create the appropriate object */
            match = reCode.matcher(entry);
            
            /* logout, create, delete, or addcredit transaction */
            if (match.matches() && match.group(1).matches("(00|01|02|06)"))
            {
                match = reUserMod.matcher(entry);
            
                if (match.matches())
                {
                    String username = match.group(2);
                    String type = match.group(3);
                    Double credit = Double.parseDouble(match.group(4));
                    
                    /* Add a logout transaction */
                    if (match.group(1).equals("00"))
                    {
                        transactions.add(new Logout(username, type, credit, entry));
                    }
                    /* Add a create transaction */
                    else if (match.group(1).equals("01"))
                    {
                        transactions.add(new Create(username, type, credit, entry));
                    }
                    /* Add a delete transaction */
                    else if (match.group(1).equals("02"))
                    {
                        transactions.add(new Delete(username, type, credit, entry));
                    }
                    /* Add a addcredit transaction */
                    else if (match.group(1).equals("06"))
                    {
                        transactions.add(new AddCredit(username, type, credit, entry));
                    }
                }
                /* This error should never be thrown -- check merge()! */
                else
                {
                    throw new FatalError(ExceptionCodes.CORRUPT_DTF, entry);
                }
            }
            /* Refund transactions */
            else if (match.group(1).matches("05"))
            {
                match = reRefund.matcher(entry);
                
                if (match.matches())
                {
                    String buyer = match.group(2);
                    String seller = match.group(3);
                    Double credit = Double.parseDouble(match.group(4));
                    
                    transactions.add(new Refund(buyer, seller, credit, entry));
                }
                /* This error should never be thrown -- check merge()! */
                else
                {
                    throw new FatalError(ExceptionCodes.CORRUPT_DTF, entry);
                }
            }
            else if (match.group(1).matches("(03|04)"))
            {
                match = reBuySell.matcher(entry);
                
                if (match.matches())
                {
                    /* Replace each _ in the event title with a space character */
                    String event = match.group(2).replace('_', ' ');
                    String seller = match.group(3);
                    Integer volume = Integer.parseInt(match.group(4));
                    Double price = Double.parseDouble(match.group(5));
                    
                    /* Add a sell transaction */
                    if (match.group(1).equals("03"))
                    {
                        transactions.add(new Sell(event, seller, volume, price, entry));
                    }
                    /* Add a buy transaction */
                    else if (match.group(1).equals("04"))
                    {
                        transactions.add(new Buy(event, seller, volume, price, entry));
                    }
                }
                /* This error should never be thrown -- check merge()! */
                else
                {
                    throw new FatalError(ExceptionCodes.CORRUPT_DTF, entry);
                }
            }
            /* This error should never be thrown -- check merge()! */
            else
            {
                throw new FatalError(ExceptionCodes.CORRUPT_DTF, entry);
            }
        }
    }
}