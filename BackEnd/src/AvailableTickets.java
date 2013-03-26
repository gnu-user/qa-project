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
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import com.google.common.base.Strings;

public class AvailableTickets
{
    private ArrayList<Ticket> tickets;
    private String atfFile;

    /**
     * Available tickets constructor
     * 
     * @param atfFile
     * @throws FatalError
     * @throws FileNotFoundException
     */
    public AvailableTickets(String atfFile) throws FatalError
    {
        File file = new File(atfFile);

        if (file.exists())
        {
            this.atfFile = atfFile;
            this.tickets = new ArrayList<Ticket>();
            
            /* Parse the available tickets file */
            parse();
        }
        else
        {
            throw new FatalError(ExceptionCodes.ATF_NOT_FOUND, atfFile);
        }
    }

    /**
     * Adds a ticket to the available tickets file
     * 
     * @param ticket
     */
    public void addTicket(Ticket ticket)
    {
        tickets.add(ticket);
    }

    /**
     * 
     * @param event
     * @param username
     * 
     * @return The ticket for the event
     */
    public Ticket getTicket(String event, String username)
    {
        for (Ticket ticket : tickets)
        {
            if (ticket.getEvent().equals(event) && ticket.getSeller().equals(username))
            {
                return ticket;
            }
        }
        
        return null;
    }

    /**
     * 
     * @param event
     * @param username
     * 
     * @return Returns true if the available tickets file has the ticket
     */
    public boolean hasTicket(String event, String username)
    {
        for (Ticket ticket : tickets)
        {
            if (ticket.getEvent().equals(event) && ticket.getSeller().equals(username))
            {
                return true;
            }
        }
        
        return false;
    }

    public void displayTickets()
    {
        for (Ticket ticket : tickets)
        {
            System.out.println(ticket.getEvent() + " " + ticket.getSeller() + " "
                    + ticket.getVolume() + " " + ticket.getPrice());

        }
    }
    
    /**
     * Write the available tickets file in memory to file, over-writing
     * the old available tickets file.
     * @throws FatalError 
     */
    public void write() throws FatalError
    {
        BufferedWriter writer;
        String entry;
        
        try 
        {
            File file = new File(atfFile + ".log");
 
            /* Create the file if it does not exist since parsed */
            if (!file.exists())
            {
                file.createNewFile();
            }
    
            writer = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
            
            /* Format each entry and write it to the file */
            for (Ticket ticket : tickets)
            {
                /* Format the event */
                entry = ticket.getEvent().replace(' ', '_');
                entry = Strings.padEnd(entry, 20, '_');
                
                /* Format the seller */
                entry += Strings.padEnd(ticket.getSeller(), 16, '_');
                
                /* Format the number of tickets */
                entry += Strings.padStart(ticket.getVolume().toString(), 3, '0') + "_";
                
                /* Format the price of tickets */
                entry += Strings.padStart(String.format("%.2f", ticket.getPrice()), 6, '0') + "\n";
                
                
                writer.write(entry);
            }
            
            /* Add the END of file identifier and close the file */
            writer.write("END_________________________________000_000.00");
            writer.close();
 
        } 
        catch (IOException e)
        {
            e.printStackTrace();
            throw new FatalError(ExceptionCodes.CORRUPT_ATF, atfFile);
        }
    }

    private void parse() throws FatalError
    {
        BufferedReader reader;

        String line;
        Pattern re = Pattern.compile("^(.{1,19}?)_+_([A-Za-z0-9_]{1,15}?)_+([0-9]{3})_([0-9]{3}\\.[0-9]{2})$");
        Pattern reEnd = Pattern.compile("END_{33}0{3}_0{3}\\.0{2}");
        Matcher match;

        try
        {
            reader = new BufferedReader(new FileReader(atfFile));
        }
        catch (FileNotFoundException e1)
        {
            e1.printStackTrace();
            throw new FatalError(ExceptionCodes.ATF_NOT_FOUND, atfFile);
        }

        try
        {
            while ((line = reader.readLine()) != null)
            {
                /* Stop if END of file reached */
                if (reEnd.matcher(line).matches())
                {
                    break;
                }

                match = re.matcher(line);
                
                /* Add each ticket found to the list of tickets */
                if (Validate.atfEntry(line) && match.matches())
                {
                    /* Replace each _ in the event title with a space character */
                    String event = match.group(1).replace('_', ' ');

                    /* Get the seller, volume, and price from regex groups */
                    String seller = match.group(2);
                    Integer volume = Integer.parseInt(match.group(3));
                    Double price = Double.parseDouble(match.group(4));

                    /* Add the ticket object to the array of tickets */
                    tickets.add(new Ticket(event, seller, volume, price));
                }
                else
                {
                    throw new FatalError(ExceptionCodes.CORRUPT_ATF, atfFile);
                }
            }
            reader.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
            throw new FatalError(ExceptionCodes.CORRUPT_ATF, atfFile);
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
                throw new FatalError(ExceptionCodes.CORRUPT_ATF, atfFile);
            }
        }
    }
}